/******************************************************************************
 * Copyright 2019 NVIDIA Corporation. All rights reserved.
 *****************************************************************************/

// examples/example_execution_native.cpp
//
// Introduces the execution of generated code for compiled materials for
// the native (CPU) backend and shows how to manually bake a material
// sub-expression to a texture.

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>

#include <mi/mdl_sdk.h>

#include "example_shared.h"
#include "texture_support.h"
#include <vector>
#include <png.h>


// Command line options structure.
struct Options {
    // An result output file name.
    std::string outputfile;

    // The resolution of the display / image.
    unsigned res_x, res_y;

    // Whether class compilation should be used for the materials.
    bool use_class_compilation;

    // Whether the custom texture runtime should be used.
    bool use_custom_tex_runtime;

    // Whether derivative support should be enabled.
    // This example does not support derivatives in combination with the custom texture runtime.
    bool enable_derivatives;

    // Material to use.
    std::string material_name;

    // List of MDL module paths.
    std::vector<std::string> mdl_paths;

    Options()
        : outputfile("example_native.png")
        , res_x(700)
        , res_y(520)
        , use_class_compilation(false)
        , use_custom_tex_runtime(false)
        , enable_derivatives(false)
    {}
};


// The last row is always implied to be (0, 0, 0, 1).
const mi::Float32_3_4 identity(
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f
);


// Helper function to extract the module name from a fully-qualified material name.
std::string get_module_name(const std::string& material_name)
{
    size_t p = material_name.rfind("::");
    return material_name.substr(0, p);
}

// Creates an instance of the given material.
void create_material_instance(
    mi::neuraylib::ITransaction* transaction,
    mi::neuraylib::IMdl_compiler* mdl_compiler,
    mi::neuraylib::IMdl_execution_context* context,
    const char* material_name,
    const char* instance_name)
{
    // Load the module.
    std::string module_name = get_module_name(material_name);
    check_success(mdl_compiler->load_module(transaction, module_name.c_str(), context) >= 0);
    print_messages(context);

    // Create a material instance from the material definition
    // Construct the material definition database name.
    std::string prefix;
    if (strncmp(material_name, "::", 2) == 0)
        prefix = "mdl";  // already has a leading "::"
    else
        prefix = "mdl::";
    std::string material_db_name = prefix + material_name;

    // Create a material instance from the material definition with the default arguments.
    mi::base::Handle<const mi::neuraylib::IMaterial_definition> material_definition(
        transaction->access<mi::neuraylib::IMaterial_definition>(material_db_name.c_str()));
    mi::Sint32 result;
    mi::base::Handle<mi::neuraylib::IMaterial_instance> material_instance(
        material_definition->create_material_instance(0, &result));
    check_success(result == 0);
    transaction->store(material_instance.get(), instance_name);
}

// Compiles the given material instance in the given compilation modes and stores it in the DB.
void compile_material_instance(
    mi::neuraylib::ITransaction* transaction,
    mi::neuraylib::IMdl_execution_context* context,
    const char* instance_name,
    const char* compiled_material_name,
    bool class_compilation)
{
    mi::base::Handle<const mi::neuraylib::IMaterial_instance> material_instance(
       transaction->access<mi::neuraylib::IMaterial_instance>(instance_name));
    mi::Uint32 flags = class_compilation
        ? mi::neuraylib::IMaterial_instance::CLASS_COMPILATION
        : mi::neuraylib::IMaterial_instance::DEFAULT_OPTIONS;
    mi::base::Handle<mi::neuraylib::ICompiled_material> compiled_material(
        material_instance->create_compiled_material(flags, context));
    check_success(print_messages(context));

    transaction->store(compiled_material.get(), compiled_material_name);
}

// Generate and execute native CPU code for a subexpression of a given compiled material.
mi::neuraylib::ITarget_code const *generate_native(
    mi::neuraylib::ITransaction* transaction,
    mi::neuraylib::IMdl_compiler* mdl_compiler,
    mi::neuraylib::IMdl_execution_context* context,
    const char* compiled_material_name,
    const char* path,
    const char* fname,
    bool use_custom_tex_runtime,
    bool enable_derivatives)
{
    mi::base::Handle<mi::neuraylib::ICompiled_material> compiled_material(
        transaction->edit<mi::neuraylib::ICompiled_material>(compiled_material_name));

    mi::base::Handle<mi::neuraylib::IMdl_backend> be_native(
        mdl_compiler->get_backend(mi::neuraylib::IMdl_compiler::MB_NATIVE));
    check_success(be_native->set_option("num_texture_spaces", "1") == 0);

    if (use_custom_tex_runtime)
        check_success(be_native->set_option("use_builtin_resource_handler", "off") == 0);

    if (enable_derivatives)
        check_success(be_native->set_option("texture_runtime_with_derivs", "on") == 0);

    // Generate the native code
    mi::base::Handle<const mi::neuraylib::ITarget_code> code_native(
        be_native->translate_material_expression(
            transaction, compiled_material.get(), path, fname, context));
    check_success(print_messages(context));
    check_success(code_native);

    code_native->retain();
    return code_native.get();
}

// Bake the material expression created with the native backend into a canvas with the given
// resolution.
std::vector<std::vector<mi::Float32_3_struct>> bake_expression_native(
    mi::neuraylib::IImage_api            *image_api,
    mi::neuraylib::ITarget_code const    *code_native,
    mi::neuraylib::Texture_handler_base  *tex_handler,
    mi::Uint32                            width,
    mi::Uint32                            height)
{
    // Create a canvas (with only one tile)
    mi::base::Handle<mi::neuraylib::ICanvas> canvas(
        image_api->create_canvas("Rgb_fp", width, height));

    // Setup MDL material state (with only one texture space)
    mi::Float32_3_struct   texture_coords[1]    = { { 0.0f, 0.0f, 0.0f } };
    mi::Float32_3_struct   texture_tangent_u[1] = { { 1.0f, 0.0f, 0.0f } };
    mi::Float32_3_struct   texture_tangent_v[1] = { { 0.0f, 1.0f, 0.0f } };

    mi::neuraylib::Shading_state_material mdl_state = {
        /*normal=*/           { 0.0f, 0.0f, 1.0f },
        /*geom_normal=*/      { 0.0f, 0.0f, 1.0f },
        /*position=*/         { 0.0f, 0.0f, 0.0f },
        /*animation_time=*/   0.0f,
        /*texture_coords=*/   texture_coords,
        /*tangent_u=*/        texture_tangent_u,
        /*tangent_v=*/        texture_tangent_v,
        /*text_results=*/     nullptr,
        /*ro_data_segment=*/  nullptr,
        /*world_to_object=*/  &identity[0],
        /*object_to_world=*/  &identity[0],
        /*object_id=*/        0
    };

    // Provide a large enough buffer for any result type.
    // In this case, we know, we will get a color which is a float3, so this is overkill.
    union
    {
        int                     int_val;
        float                   float_val;
        double                  double_val;
        mi::Float32_3_struct    float3_val;
        mi::Float32_4_struct    float4_val;
        mi::Float32_4_4_struct  float4x4_val;
        mi::Float64_3_struct    double3_val;
        mi::Float64_4_struct    double4_val;
        mi::Float64_4_4_struct  double4x4_val;
    } execute_result = { 0 };

    // Calculate all expression values for a 2x2 quad around the center of the world
    // and write them to the canvas.
    mi::base::Handle<mi::neuraylib::ITile> tile(canvas->get_tile(0, 0));
    auto buffer = std::vector<std::vector<mi::Float32_3_struct>>();
    auto start = std::chrono::system_clock::now();
    for (mi::Uint32 y = 0; y < height; ++y) {
        buffer.emplace_back(std::vector<mi::Float32_3_struct>());
        for (mi::Uint32 x = 0; x < width; ++x) {
            // Update state for the current pixel
            float rel_x = float(x) / float(width);
            float rel_y = float(y) / float(height);
            mdl_state.position.x = 2.0f * rel_x - 1;  // [-1, 1)
            mdl_state.position.y = 2.0f * rel_y - 1;  // [-1, 1)
            texture_coords[0].x  = rel_x;             // [0, 1)
            texture_coords[0].y  = rel_y;             // [0, 1)

            // Evaluate sub-expression
            check_success(
                code_native->execute(0, mdl_state, tex_handler, nullptr, &execute_result) == 0);

            // Apply gamma correction
            /*execute_result.float3_val.x = powf(execute_result.float3_val.x, 1.f / 2.2f);
            execute_result.float3_val.y = powf(execute_result.float3_val.y, 1.f / 2.2f);
            execute_result.float3_val.z = powf(execute_result.float3_val.z, 1.f / 2.2f);*/

            // Store result in texture
            buffer[y].push_back(execute_result.float3_val);
        }
    }

    auto end = std::chrono::system_clock::now();
    std::cout << "elapsed " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    return buffer;
}

// Bake the material expression created with the native backend into a canvas with the given
// resolution with derivative support.
mi::neuraylib::ICanvas *bake_expression_native_with_derivs(
    mi::neuraylib::IImage_api            *image_api,
    mi::neuraylib::ITarget_code const    *code_native,
    mi::neuraylib::Texture_handler_base  *tex_handler,
    mi::Uint32                            width,
    mi::Uint32                            height)
{
    // Create a canvas (with only one tile)
    mi::base::Handle<mi::neuraylib::ICanvas> canvas(
        image_api->create_canvas("Rgb_fp", width, height));

    // Setup MDL material state (with only one texture space)
    float step_x = 1.f / width;
    float step_y = 1.f / height;

    mi::neuraylib::tct_deriv_float3 texture_coords[1] = {
        {
            { 0.0f, 0.0f, 0.0f },     // value component
            { step_x, 0.0f, 0.0f },   // dx component
            { 0.0f, step_y, 0.0f }    // dy component
        } };
    mi::neuraylib::tct_float3 texture_tangent_u[1] = { { 1.0f, 0.0f, 0.0f } };
    mi::neuraylib::tct_float3 texture_tangent_v[1] = { { 0.0f, 1.0f, 0.0f } };

    mi::neuraylib::Shading_state_material_with_derivs mdl_state = {
        /*normal=*/           { 0.0f, 0.0f, 1.0f },
        /*geom_normal=*/      { 0.0f, 0.0f, 1.0f },
        /*position=*/         { 0.0f, 0.0f, 0.0f },
        /*animation_time=*/   0.0f,
        /*texture_coords=*/   texture_coords,
        /*tangent_u=*/        texture_tangent_u,
        /*tangent_v=*/        texture_tangent_v,
        /*text_results=*/     nullptr,
        /*ro_data_segment=*/  nullptr,
        /*world_to_object=*/  &identity[0],
        /*object_to_world=*/  &identity[0],
        /*object_id=*/        0
    };

    // Provide a large enough buffer for any result type.
    // In this case, we know, we will get a color which is a float3, so this is overkill.
    union
    {
        int                     int_val;
        float                   float_val;
        double                  double_val;
        mi::Float32_3_struct    float3_val;
        mi::Float32_4_struct    float4_val;
        mi::Float32_4_4_struct  float4x4_val;
        mi::Float64_3_struct    double3_val;
        mi::Float64_4_struct    double4_val;
        mi::Float64_4_4_struct  double4x4_val;
    } execute_result = { 0 };

    // Calculate all expression values for a 2x2 quad around the center of the world
    // and write them to the canvas.
    mi::base::Handle<mi::neuraylib::ITile> tile(canvas->get_tile(0, 0));
    mi::Float32_3_struct *data = static_cast<mi::Float32_3_struct *>(tile->get_data());
    for (mi::Uint32 y = 0; y < height; ++y) {
        for (mi::Uint32 x = 0; x < width; ++x) {
            // Update state for the current pixel
            float rel_x = x * step_x;
            float rel_y = y * step_y;
            mdl_state.position.x    = 2.0f * rel_x - 1;  // [-1, 1)
            mdl_state.position.y    = 2.0f * rel_y - 1;  // [-1, 1)
            texture_coords[0].val.x = rel_x;             // [0, 1)
            texture_coords[0].val.y = rel_y;             // [0, 1)

            // Evaluate sub-expression
            check_success(code_native->execute(
                0,
                reinterpret_cast<mi::neuraylib::Shading_state_material &>(mdl_state),
                tex_handler,
                nullptr,
                &execute_result) == 0);

            // Apply gamma correction
            execute_result.float3_val.x = powf(execute_result.float3_val.x, 1.f / 2.2f);
            execute_result.float3_val.y = powf(execute_result.float3_val.y, 1.f / 2.2f);
            execute_result.float3_val.z = powf(execute_result.float3_val.z, 1.f / 2.2f);

            // Store result in texture
            data[y * width + x] = execute_result.float3_val;
        }
    }

    canvas->retain();
    return canvas.get();
}

// Prepare the textures for our own texture runtime.
bool prepare_textures(
    std::vector<Texture>& textures,
    mi::neuraylib::ITransaction* transaction,
    mi::neuraylib::IImage_api* image_api,
    const mi::neuraylib::ITarget_code* target_code)
{
    for (mi::Size i = 1 /*skip invalid texture*/; i < target_code->get_texture_count(); ++i)
    {
        mi::base::Handle<const mi::neuraylib::ITexture> texture(
            transaction->access<const mi::neuraylib::ITexture>(
                target_code->get_texture(i)));
        mi::base::Handle<const mi::neuraylib::IImage> image(
            transaction->access<mi::neuraylib::IImage>(texture->get_image()));
        mi::base::Handle<const mi::neuraylib::ICanvas> canvas(image->get_canvas());
        char const *image_type = image->get_type();

        if (image->is_uvtile()) {
            std::cerr << "The example does not support uvtile textures!" << std::endl;
            return false;
        }

        if (canvas->get_tiles_size_x() != 1 || canvas->get_tiles_size_y() != 1) {
            std::cerr << "The example does not support tiled images!" << std::endl;
            return false;
        }

        // For simplicity, the texture access functions are only implemented for float4 and gamma
        // is pre-applied here (all images are converted to linear space).

        // Convert to linear color space if necessary
        if (texture->get_effective_gamma() != 1.0f) {
            // Copy/convert to float4 canvas and adjust gamma from "effective gamma" to 1.
            mi::base::Handle<mi::neuraylib::ICanvas> gamma_canvas(
                image_api->convert(canvas.get(), "Color"));
            gamma_canvas->set_gamma(texture->get_effective_gamma());
            image_api->adjust_gamma(gamma_canvas.get(), 1.0f);
            canvas = gamma_canvas;
        }
        else if (strcmp(image_type, "Color") != 0 && strcmp(image_type, "Float32<4>") != 0) {
            // Convert to expected format
            canvas = image_api->convert(canvas.get(), "Color");
        }
        textures.push_back(Texture(canvas));
    }
    return true;
}

// Print command line usage to console and terminate the application.
void usage(char const *prog_name)
{
    std::cout
        << "Usage: " << prog_name << " [options] [<material_name>]\n"
        << "Options:\n"
        << "  --res <x> <y>       resolution (default: 700x520)\n"
        << "  --cc                use class compilation\n"
        << "  --cr                use custom texture runtime\n"
        << "  -d                  enable use of derivatives\n"
        << "                      (not supported in combination with --cr by this example)\n"
        << "  -o <outputfile>     image file to write result to\n"
        << "                      (default: example_native.png)\n"
        << "  --mdl_path <path>   mdl search path, can occur multiple times."
        << std::endl;
    keep_console_open();
    exit(EXIT_FAILURE);
}


//------------------------------------------------------------------------------
//
// Main function
//
//------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    // Parse command line options
    Options options;

    for (int i = 1; i < argc; ++i) {
        char const *opt = argv[i];
        if (opt[0] == '-') {
            if (strcmp(opt, "-o") == 0 && i < argc - 1) {
                options.outputfile = argv[++i];
            } else if (strcmp(opt, "--res") == 0 && i < argc - 2) {
                options.res_x = std::max(atoi(argv[++i]), 1);
                options.res_y = std::max(atoi(argv[++i]), 1);
            } else if (strcmp(opt, "--cc") == 0) {
                options.use_class_compilation = true;
            } else if (strcmp(opt, "--cr") == 0) {
                options.use_custom_tex_runtime = true;
            } else if (strcmp(opt, "-d") == 0) {
                options.enable_derivatives = true;
            } else if (strcmp(opt, "--mdl_path") == 0 && i < argc - 1) {
                options.mdl_paths.push_back(argv[++i]);
            } else {
                std::cout << "Unknown option: \"" << opt << "\"" << std::endl;
                usage(argv[0]);
            }
        } else
            options.material_name = opt;
    }

    if (options.use_custom_tex_runtime && options.enable_derivatives) {
        std::cout << "This example does not support using derivatives with the custom texture "
            "runtime.\n";
        usage(argv[0]);
    }

    // Use default material, if none was provided via command line
    if (options.material_name.empty()) {
        options.mdl_paths.push_back(get_samples_mdl_root());
        options.material_name = "::nvidia::sdk_examples::presentation_perlin_noise::summed_noise_material";
    }

    // Access the MDL SDK
    mi::base::Handle<mi::neuraylib::INeuray> neuray(load_and_get_ineuray());
    check_success(neuray.is_valid_interface());

    // Access the MDL SDK compiler component
    mi::base::Handle<mi::neuraylib::IMdl_compiler> mdl_compiler(
        neuray->get_api_component<mi::neuraylib::IMdl_compiler>());

    // Configure the MDL SDK
    // Load plugin required for loading textures
    check_success(mdl_compiler->load_plugin_library("nv_freeimage" MI_BASE_DLL_FILE_EXT) == 0);
    // Configure MDL search root
    for (std::size_t i = 0; i < options.mdl_paths.size(); ++i)
        check_success(mdl_compiler->add_module_path(options.mdl_paths[i].c_str()) == 0);

    // Start the MDL SDK
    mi::Sint32 result = neuray->start();
    check_start_success(result);

    {
        // Create a transaction
        mi::base::Handle<mi::neuraylib::IDatabase> database(
            neuray->get_api_component<mi::neuraylib::IDatabase>());
        mi::base::Handle<mi::neuraylib::IScope> scope(database->get_global_scope());
        mi::base::Handle<mi::neuraylib::ITransaction> transaction(scope->create_transaction());
        {
            mi::base::Handle<mi::neuraylib::IMdl_factory> mdl_factory(
                neuray->get_api_component<mi::neuraylib::IMdl_factory>());

            mi::base::Handle<mi::neuraylib::IMdl_execution_context> context(
                mdl_factory->create_execution_context());

            // Load the MDL module and create a material instance
            std::string instance_name = "material instance";
            create_material_instance(
                transaction.get(),
                mdl_compiler.get(),
                context.get(),
                options.material_name.c_str(),
                instance_name.c_str());

            // Compile the material instance in instance compilation mode
            std::string instance_compilation_name
                = std::string("instance compilation of ") + instance_name;
            // Compile the material instance
            std::string compilation_name
                = std::string("compilation of ") + instance_name;
            compile_material_instance(
                transaction.get(),
                context.get(),
                instance_name.c_str(),
                compilation_name.c_str(),
                options.use_class_compilation);

            // Generate target code for some material expression
            mi::base::Handle<const mi::neuraylib::ITarget_code> target_code(
                generate_native(
                    transaction.get(),
                    mdl_compiler.get(),
                    context.get(),
                    compilation_name.c_str(),
                    "surface.scattering.tint",            // MDL expression path
                    "tint",                               // name of generated function
                    options.use_custom_tex_runtime,
                    options.enable_derivatives));

            // Acquire image API needed to create a canvas for baking
            mi::base::Handle<mi::neuraylib::IImage_api> image_api(
                neuray->get_api_component<mi::neuraylib::IImage_api>());

            mi::base::Handle<mi::neuraylib::ICanvas> canvas;

            std::vector<Texture>  textures;
            Texture_handler       tex_handler;
            Texture_handler      *tex_handler_ptr = nullptr;
            if (options.use_custom_tex_runtime) {
                // Setup custom texture handler
                check_success(prepare_textures(
                    textures, transaction.get(), image_api.get(), target_code.get()));

                tex_handler.vtable = &tex_vtable;
                tex_handler.num_textures = target_code->get_texture_count() - 1;
                tex_handler.textures = textures.data();

                tex_handler_ptr = &tex_handler;
            }

            auto data = bake_expression_native(
                    image_api.get(), target_code.get(), tex_handler_ptr,
                    options.res_x, options.res_y);

            auto file = fopen((options.outputfile + ".ppm").c_str() , "wb");
            fprintf(file, "P3\n%d %d\n255\n", options.res_x, options.res_y);
            for(int y = options.res_y-1; y >= 0; y--){
                for (int x = 0; x < options.res_x; ++x) {
                    if(x > 0){
                        fprintf(file, " ");
                    }
                    fprintf(file, "%i %i %i", static_cast<int>(data[y][x].x * 255), static_cast<int>(data[y][x].y * 255),static_cast<int>(data[y][x].z * 255));
                }
                fprintf(file, "\n");
            }
            fclose(file);
            // Export the canvas to an image on disk
            //l_compiler->export_canvas(options.outputfile.c_str(), canvas.get());
        }

        transaction->commit();
    }

    // Free MDL compiler before shutting down MDL SDK
    mdl_compiler = 0;

    // Shut down the MDL SDK
    check_success(neuray->shutdown() == 0);
    neuray = 0;

    // Unload the MDL SDK
    check_success(unload());

    keep_console_open();
    return EXIT_SUCCESS;
}
