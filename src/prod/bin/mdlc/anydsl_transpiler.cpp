//
// Created by Noisyedge on 2019-05-19.
//

#include "anydsl_transpiler.h"

#include "custom_assert.h"
#include "pch.h"

#include <mi/base/handle.h>
#include <mi/mdl/mdl_code_generators.h>

#include <mdl/codegenerators/generator_code/generator_code_hash.h>
#include <mdl/compiler/compilercore/compilercore_cc_conf.h>
#include <mdl/compiler/compilercore/compilercore_file_resolution.h>
#include <mdl/compiler/compilercore/compilercore_mdl.h>
#include <mdl/compiler/compilercore/compilercore_streams.h>
#include <mdl/compiler/compilercore/compilercore_visitor.h>

#include <cstring>

namespace mi {
    namespace mdl {

        void AnyDSL_Transpiler::transpile_module(const IModule *module) {

            /*for (int i = 0; i < module->get_import_count(); i++) {
                const IModule *m = module->get_import(i);
                if (imports.find(std::string(m->get_name())) != imports.end() || strcmp(m->get_name(), "::<builtins>") == 0) {
                    continue;
                }
                imports.insert(std::string(m->get_name()));
                transpile_module(m);

            }*/

            for (int i = 0, n = module->get_exported_definition_count(); i < n; ++i) {
                IDefinition const *def = module->get_exported_definition(i);
                dispatch_transpile_definition(def);
            }





            /*for (int i = 0; i < module->get_declaration_count(); i++) {
                const IDeclaration *decl = module->get_declaration(i);
                dispatch_transpile_declaration(decl);
            }

            for (int i = 0; i < module->get_builtin_definition_count(); i++) {
                const IDefinition *def = module->get_builtin_definition(i);
                dispatch_transpile_definition(def);
            }*/


        }

        void AnyDSL_Transpiler::dispatch_transpile_definition(const IDefinition *def) {
            switch (def->get_kind()) {
                case IDefinition::DK_ERROR:
                    break;
                case IDefinition::DK_CONSTANT:
                    transpile_constant(def);
                    break;
                case IDefinition::DK_ENUM_VALUE:
                    transpile_enum_value(def);
                    break;
                case IDefinition::DK_ANNOTATION:
                    transpile_annotation(def);
                    break;
                case IDefinition::DK_TYPE:
                    transpile_type(def);
                    break;
                case IDefinition::DK_FUNCTION:
                    transpile_function(def);
                    break;
                case IDefinition::DK_VARIABLE:
                    transpile_variable(def);
                    break;
                case IDefinition::DK_MEMBER:
                    transpile_member(def);
                    break;
                case IDefinition::DK_CONSTRUCTOR:
                    transpile_constructor(def);
                    break;
                case IDefinition::DK_PARAMETER:
                    transpile_parameter(def);
                    break;
                case IDefinition::DK_ARRAY_SIZE:
                    transpile_array_size(def);
                    break;
                case IDefinition::DK_OPERATOR:
                    transpile_operator(def);
                    break;
            }
        }

        void AnyDSL_Transpiler::transpile_constant(const IDefinition *definition) {
            add_to_code("static ", true);
            add_to_code(definition->get_symbol()->get_name());
            add_to_code(" : ");
            add_to_code(type_to_string_for_mangling(definition->get_type()));
            add_to_code(" = ");
            add_to_code(value_to_string(definition->get_constant_value()));
            add_to_code(";\n");


        }

        void AnyDSL_Transpiler::transpile_enum_value(const IDefinition *definition) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_annotation(const IDefinition *definition) {
            return;
        }

        void AnyDSL_Transpiler::transpile_type(const IDefinition *definition) {
            auto t = definition->get_type()->get_kind();
            switch (t) {

                case IType::TK_ENUM:
                    add_to_code("enum ", true);
                    break;
                case IType::TK_STRUCT:
                    add_to_code("struct ", true);
                    break;
                case IType::TK_TEXTURE:
                    add_to_code("texture ", true);
                    break;
                case IType::TK_BSDF_MEASUREMENT:
                    add_to_code("bsdf_measurement ", true);
                    break;
                case IType::TK_BSDF:
                    add_to_code("bsdf ", true);
                    break;
                case IType::TK_VDF:
                    add_to_code("vdf ", true);
                    break;
                case IType::TK_EDF:
                    add_to_code("edf ", true);
                    break;
                case IType::TK_LIGHT_PROFILE:
                    add_to_code("light_profile ", true);
                    break;
                case IType::TK_MATRIX:
                    add_to_code("matrix ", true);
                    break;
                case IType::TK_COLOR:
                    add_to_code("color ", true);
                    break;
                case IType::TK_STRING:
                    add_to_code("string ", true);
                    break;
                case IType::TK_VECTOR:
                    add_to_code("vector ", true);
                    break;
                case IType::TK_DOUBLE:
                    add_to_code("double ", true);
                    break;
                case IType::TK_BOOL:
                    add_to_code("bool ", true);
                    break;
                case IType::TK_FLOAT:
                    add_to_code("float ", true);
                    break;
                case IType::TK_INT:
                    add_to_code("int ", true);
                    break;
                default:
                    NOT_IMPLEMENTED;
            }
            add_to_code(definition->get_symbol()->get_name());
            if (definition->get_declaration() != nullptr) {
                dispatch_transpile_declaration(definition->get_declaration());
            } else {
                add_to_code(";\n");
            }

        }

        void AnyDSL_Transpiler::transpile_function(const IDefinition *definition) {
            const IType_function *fun_type = as<IType_function>(definition->get_type());
            int parameter_count = fun_type->get_parameter_count();
            std::vector<std::string> argument_types = std::vector<std::string>(parameter_count);
            std::vector<std::string> argument_names = std::vector<std::string>(parameter_count);
            std::vector<std::string> argument_types_mangling = std::vector<std::string>(parameter_count);

            auto fname = std::string(definition->get_symbol()->get_name());

            for (int k = 0; k < parameter_count; ++k) {
                IType const *parameter_type = nullptr;
                ISymbol const *parameter_symbol = nullptr;

                fun_type->get_parameter(k, parameter_type, parameter_symbol);

                argument_types_mangling[k] = type_to_string_for_mangling(parameter_type);
                argument_types[k] = type_to_string(parameter_type);

                argument_names[k] = parameter_symbol->get_name();
            }


            add_to_code("fn ", true);
            add_to_code(fname);
            add_to_code("_");
            for (int i = 0; i < argument_types.size(); i++) {
                add_to_code("_");
                add_to_code(argument_types_mangling[i]);
            }
            if (definition->get_property(IDefinition::Property::DP_USES_STATE)) {
                add_to_code("_State");
            }
            add_to_code("_mdl_math");
            add_to_code("(");
            for (int i = 0; i < argument_names.size(); i++) {
                add_to_code(argument_names[i]);
                add_to_code(" : ");
                add_to_code(argument_types[i]);
                add_to_code(",");
            }
            if (definition->get_property(IDefinition::Property::DP_USES_STATE)) {
                add_to_code(" state : State,");
            }
            add_to_code(" math : mdl_math");
            add_to_code(") -> ");
            add_to_code(type_to_string(fun_type->get_return_type()));
            if (definition->get_declaration() != nullptr) {
                add_to_code("{\n", true);
                indent_level++;
                dispatch_transpile_declaration(definition->get_declaration());
                indent_level--;
                add_to_code("}\n", true);
            } else {
                add_to_code(";\n");
            }


        }

        void AnyDSL_Transpiler::transpile_constructor(const IDefinition *definition) {
            transpile_function(definition);
        }

        void AnyDSL_Transpiler::transpile_operator(const IDefinition *definition) {
            transpile_function(definition);
        }

        void AnyDSL_Transpiler::transpile_member(const IDefinition *definition) {
            UNREACHABLE;
        }

        void AnyDSL_Transpiler::transpile_parameter(const IDefinition *definition) {
            UNREACHABLE;
        }

        void AnyDSL_Transpiler::transpile_array_size(const IDefinition *definition) {
            UNREACHABLE;
        }

        void AnyDSL_Transpiler::transpile_variable(const IDefinition *definition) {
            add_to_code("let mut ", true);
            add_to_code(definition->get_symbol()->get_name());
            add_to_code(" : ");
            if (definition->get_property(IDefinition::Property::DP_IS_VARYING)) {
                add_to_code("fn(");
                if (definition->get_property(IDefinition::Property::DP_USES_STATE) ||
                    definition->get_property(IDefinition::Property::DP_USES_VARYING_STATE)) {
                    add_to_code("State");
                }
                add_to_code(") -> ");
                add_to_code(type_to_string(definition->get_type()));
                if (definition->get_declaration() != nullptr) {
                    add_to_code(" = {");
                    dispatch_transpile_declaration(definition->get_declaration());
                    add_to_code("}");
                }
            } else {
                add_to_code(type_to_string(definition->get_type()));
                if (definition->get_declaration() != nullptr) {
                    add_to_code(" = ");
                    dispatch_transpile_declaration(definition->get_declaration());
                }
            }

            add_to_code(";\n");
        }

        const std::string AnyDSL_Transpiler::type_to_string(const IType *type) {
            std::string ts;
            switch (type->get_kind()) {
                case IType::TK_ALIAS: {
                    const IType_alias *t = as<IType_alias>(type);
                    ts = type_to_string(t->get_aliased_type());
                    break;
                }
                case IType::TK_BOOL:
                    ts = "bool";
                    break;
                case IType::TK_INT:
                    ts = "int";
                    break;
                case IType::TK_ENUM: {
                    const IType_enum *t = as<IType_enum>(type);
                    ts = t->get_symbol()->get_name();
                    break;
                }
                case IType::TK_FLOAT:
                    ts = "float";
                    break;
                case IType::TK_DOUBLE:
                    ts = "double";
                    break;
                case IType::TK_STRING:
                    ts = "string";
                    break;
                case IType::TK_LIGHT_PROFILE:
                    ts = "light_profile";
                    break;
                case IType::TK_BSDF:
                    ts = "bsdf";
                    break;
                case IType::TK_EDF:
                    ts = "edf";
                    break;
                case IType::TK_VDF:
                    ts = "vdf";
                    break;
                case IType::TK_VECTOR: {
                    auto t = as<IType_vector>(type);
                    ts = type_to_string(t->get_element_type()) + std::to_string(t->get_size());
                    break;
                }
                case IType::TK_MATRIX: {
                    const IType_matrix *t = as<IType_matrix>(type);
                    ts = type_to_string(t->get_element_type()) + "x" + std::to_string(t->get_columns());
                    break;
                }


                case IType::TK_ARRAY: {
                    auto t = as<IType_array>(type);
                    std::string s1("[");
                    std::string s2("]");
                    std::string s3(type_to_string(t->get_element_type()));
                    std::string s4 = std::to_string(t->get_size());
                    std::string s5("*");
                    auto str = std::string();
                    str = s1 + s3 + s5 + s4 + s2;
                    ts = str;
                    break;
                }

                case IType::TK_COLOR:
                    ts = "color";
                    break;
                case IType::TK_FUNCTION: {
                    const auto *t = as<IType_function>(type);
                    std::string s1("(");
                    std::string s2(") -> (");
                    std::string s3(")");
                    std::string s4(",");
                    const IType *itype;
                    const ISymbol *iSymbol;
                    auto str = std::string();
                    str += "(";
                    for (int i = 0; i < t->get_parameter_count(); i++) {
                        if (i != 0) {
                            str += ",";
                        }
                        t->get_parameter(i, itype, iSymbol);
                        str += iSymbol->get_name();
                    }
                    str += ") -> (";
                    str += type_to_string(t->get_return_type());
                    str += ")";

                    ts = str;
                    break;
                }

                case IType::TK_STRUCT: {
                    const auto *t = as<IType_struct>(type);
                    ts = t->get_symbol()->get_name();
                    break;
                }

                case IType::TK_TEXTURE: {
                    const IType_texture *tex = as<IType_texture>(type);
                    switch (tex->get_shape()) {
                        case IType_texture::TS_2D:
                            ts = "texture_2d";
                            break;
                        case IType_texture::TS_3D:
                            ts = "texture_3d";
                            break;
                        case IType_texture::TS_CUBE:
                            ts = "texture_cube";
                            break;
                        case IType_texture::TS_PTEX:
                            ts = "texture_ptex";
                            break;
                    }
                    break;
                }

                case IType::TK_BSDF_MEASUREMENT:
                    ts = "bsdf_measurement";
                    break;
                case IType::TK_INCOMPLETE:
                    ts = "";
                    break;
                case IType::TK_ERROR:
                    ts = "";
                    break;
            }

            return "fn(State) -> " + ts;


        }


        const std::string AnyDSL_Transpiler::type_to_string_for_mangling(const IType *type) {
            std::string ts;
            switch (type->get_kind()) {
                case IType::TK_ALIAS: {
                    const IType_alias *t = as<IType_alias>(type);
                    ts = type_to_string(t->get_aliased_type());
                    break;
                }
                case IType::TK_BOOL:
                    ts = "bool";
                    break;
                case IType::TK_INT:
                    ts = "int";
                    break;
                case IType::TK_ENUM: {
                    const IType_enum *t = as<IType_enum>(type);
                    ts = t->get_symbol()->get_name();
                    break;
                }
                case IType::TK_FLOAT:
                    ts = "float";
                    break;
                case IType::TK_DOUBLE:
                    ts = "double";
                    break;
                case IType::TK_STRING:
                    ts = "string";
                    break;
                case IType::TK_LIGHT_PROFILE:
                    ts = "light_profile";
                    break;
                case IType::TK_BSDF:
                    ts = "bsdf";
                    break;
                case IType::TK_EDF:
                    ts = "edf";
                    break;
                case IType::TK_VDF:
                    ts = "vdf";
                    break;
                case IType::TK_VECTOR: {
                    auto t = as<IType_vector>(type);
                    ts = type_to_string(t->get_element_type()) + std::to_string(t->get_size());
                    break;
                }
                case IType::TK_MATRIX: {
                    const IType_matrix *t = as<IType_matrix>(type);
                    ts = type_to_string(t->get_element_type()) + "x" + std::to_string(t->get_columns());
                    break;
                }


                case IType::TK_ARRAY: {
                    auto t = as<IType_array>(type);
                    std::string s1("[");
                    std::string s2("]");
                    std::string s3(type_to_string(t->get_element_type()));
                    std::string s4 = std::to_string(t->get_size());
                    std::string s5("*");
                    auto str = std::string();
                    str = s1 + s3 + s5 + s4 + s2;
                    ts = str;
                    break;
                }

                case IType::TK_COLOR:
                    ts = "color";
                    break;
                case IType::TK_FUNCTION: {
                    const auto *t = as<IType_function>(type);
                    std::string s1("(");
                    std::string s2(") -> (");
                    std::string s3(")");
                    std::string s4(",");
                    const IType *itype;
                    const ISymbol *iSymbol;
                    auto str = std::string();
                    str += "(";
                    for (int i = 0; i < t->get_parameter_count(); i++) {
                        if (i != 0) {
                            str += ",";
                        }
                        t->get_parameter(i, itype, iSymbol);
                        str += iSymbol->get_name();
                    }
                    str += ") -> (";
                    str += type_to_string(t->get_return_type());
                    str += ")";

                    ts = str;
                    break;
                }

                case IType::TK_STRUCT: {
                    const auto *t = as<IType_struct>(type);
                    ts = t->get_symbol()->get_name();
                    break;
                }

                case IType::TK_TEXTURE: {
                    const IType_texture *tex = as<IType_texture>(type);
                    switch (tex->get_shape()) {
                        case IType_texture::TS_2D:
                            ts = "texture_2d";
                            break;
                        case IType_texture::TS_3D:
                            ts = "texture_3d";
                            break;
                        case IType_texture::TS_CUBE:
                            ts = "texture_cube";
                            break;
                        case IType_texture::TS_PTEX:
                            ts = "texture_ptex";
                            break;
                    }
                    break;
                }

                case IType::TK_BSDF_MEASUREMENT:
                    ts = "bsdf_measurement";
                    break;
                case IType::TK_INCOMPLETE:
                    ts = "";
                    break;
                case IType::TK_ERROR:
                    ts = "";
                    break;
            }

            return ts;


        }

        void AnyDSL_Transpiler::dispatch_transpile_declaration(
                const IDeclaration *decl) {
            switch (decl->get_kind()) {
                case IDeclaration::DK_INVALID:
                    break;
                case IDeclaration::DK_IMPORT:
                    transpile_import(decl);
                    break;
                case IDeclaration::DK_ANNOTATION:
                    transpile_annotation_declaration(decl);
                    break;
                case IDeclaration::DK_CONSTANT:
                    transpile_constant_declaration(decl);
                    break;
                case IDeclaration::DK_TYPE_ALIAS:
                    transpile_type_alias(decl);
                    break;
                case IDeclaration::DK_TYPE_STRUCT:
                    transpile_struct(decl);
                    break;
                case IDeclaration::DK_TYPE_ENUM:
                    transpile_enum_declaration(decl);
                    break;
                case IDeclaration::DK_VARIABLE:
                    transpile_variable_declaration(decl);
                    break;
                case IDeclaration::DK_FUNCTION:
                    transpile_function_declaration(decl);
                    break;
                case IDeclaration::DK_MODULE:
                    transpile_module_declaration(decl);
                    break;
            }
        }

        void AnyDSL_Transpiler::transpile_module_declaration(const IDeclaration *decl) {
            NOT_IMPLEMENTED;
            const auto *d = as<IDeclaration_module>(decl);
        }

        void AnyDSL_Transpiler::transpile_function_declaration(
                const IDeclaration *pDeclaration) {
            auto *d = as<IDeclaration_function>(pDeclaration);

            const IStatement *s = d->get_body();
            if (s != nullptr) {
                dispatch_transpile_statement(s);
            } else {
                add_to_code("{}\n");
            }
        }

        void AnyDSL_Transpiler::transpile_import(const IDeclaration *decl) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_type_alias(const IDeclaration *decl) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_struct(const IDeclaration *decl) {
            const IDeclaration_type_struct *s = as<IDeclaration_type_struct>(decl);
            add_to_code(" {\n", true);
            indent_level++;
            for (int i = 0; i < s->get_field_count(); i++) {
                add_to_code(s->get_field_name(i)->get_symbol()->get_name(), true);
                add_to_code(": ");
                add_to_code(type_to_string(s->get_field_type_name(i)->get_type()));
                add_to_code(",\n");
            }
            indent_level--;
            add_to_code("}\n\n", true);
            add_to_code("fn ", true);
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code("_() -> ");
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code(" {\n");
            indent_level++;
            add_to_code(s->get_name()->get_symbol()->get_name(), true);
            add_to_code("{\n");
            indent_level++;
            for (int i = 0; i < s->get_field_count(); i++) {
                add_to_code(s->get_field_name(i)->get_symbol()->get_name(), true);
                add_to_code(": ");
                auto e = s->get_field_init(i);
                if (e != nullptr) {
                    dispatch_transpile_expression(s->get_field_init(i));
                } else {
                    add_to_code(type_to_string(s->get_field_type_name(i)->get_type()));
                    add_to_code("_()");
                }
                add_to_code(",\n");
            }
            indent_level--;
            add_to_code("}\n", true);
            indent_level--;
            add_to_code("}\n", true);

            add_to_code("fn ", true);
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code("_");
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code("(copy: ");
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code(") -> ");
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code(" {\n");
            indent_level++;
            add_to_code(s->get_name()->get_symbol()->get_name(), true);
            add_to_code("{\n");
            indent_level++;
            for (int i = 0; i < s->get_field_count(); i++) {
                add_to_code(s->get_field_name(i)->get_symbol()->get_name(), true);
                add_to_code(": copy.");
                add_to_code(s->get_field_name(i)->get_symbol()->get_name());
                add_to_code(",\n");
            }
            indent_level--;
            add_to_code("}\n", true);
            indent_level--;
            add_to_code("}\n", true);


        }

        void AnyDSL_Transpiler::transpile_enum_declaration(const IDeclaration *decl) {
            const IDeclaration_type_enum *e = as<IDeclaration_type_enum>(decl);
            add_to_code("{\n");
            indent_level++;
            for (int i = 0; i < e->get_value_count(); i++) {
                add_to_code(e->get_value_name(i)->get_symbol()->get_name(), true);
                add_to_code(",\n");
            }
            indent_level--;
            add_to_code("}\n", true);
        }

        void AnyDSL_Transpiler::transpile_variable_declaration(const IDeclaration *decl) {

            const IDeclaration_variable *v = as<IDeclaration_variable>(decl);
            for (int i = 0; i < v->get_variable_count(); i++) {
                const IDefinition *definition = v->get_variable_name(i)->get_definition();
                if (i > 0) {
                    add_to_code(";\n");
                    add_to_code("", true);
                }
                add_to_code("let mut ");
                add_to_code(v->get_variable_name(i)->get_symbol()->get_name());
                add_to_code(": ");
                if (!definition->get_property(IDefinition::Property::DP_IS_VARYING)) {
                    add_to_code("fn(");
                    if (definition->get_property(IDefinition::Property::DP_USES_STATE) ||
                        definition->get_property(IDefinition::Property::DP_USES_VARYING_STATE)) {
                        add_to_code("State");
                    }
                    add_to_code(") -> ");
                    add_to_code(type_to_string(v->get_type_name()->get_type()));

                    add_to_code(" = {");
                    dispatch_transpile_expression(v->get_variable_init(i));
                    add_to_code("}");

                } else {
                    add_to_code(type_to_string(v->get_type_name()->get_type()));
                    if (v->get_variable_init(i) != nullptr) {
                        add_to_code(" = ");
                        dispatch_transpile_expression(v->get_variable_init(i));
                    }
                }


            }
        }

        void AnyDSL_Transpiler::transpile_constant_declaration(const IDeclaration *decl) {
            const IDeclaration_constant *c = as<IDeclaration_constant>(decl);
            for (int i = 0; i < c->get_constant_count(); i++) {
                add_to_code("static ", true);
                add_to_code(c->get_constant_name(i)->get_symbol()->get_name());
                add_to_code(": ");
                add_to_code(type_to_string(c->get_type_name()->get_type()));
                if (c->get_constant_exp(i) != nullptr) {
                    add_to_code(" = ");
                    dispatch_transpile_expression(c->get_constant_exp(i));
                }
                add_to_code(";\n");
            }
        }

        void AnyDSL_Transpiler::transpile_annotation_declaration(
                const IDeclaration *decl) {
            return;
        }

        void AnyDSL_Transpiler::dispatch_transpile_statement(const IStatement *stat) {
            switch (stat->get_kind()) {
                case IStatement::SK_INVALID:
                    break;
                case IStatement::SK_COMPOUND:
                    transpile_compound_statement(stat);
                    break;
                case IStatement::SK_DECLARATION:
                    transpile_declaration_statement(stat);
                    break;
                case IStatement::SK_EXPRESSION:
                    transpile_expression_statement(stat);
                    break;
                case IStatement::SK_IF:
                    transpile_if_statement(stat);
                    break;
                case IStatement::SK_CASE:
                    transpile_case_statement(stat);
                    break;
                case IStatement::SK_SWITCH:
                    transpile_switch_statement(stat);
                    break;
                case IStatement::SK_WHILE:
                    transpile_while_statement(stat);
                    break;
                case IStatement::SK_DO_WHILE:
                    transpile_do_while_statement(stat);
                    break;
                case IStatement::SK_FOR:
                    transpile_for_statement(stat);
                    break;
                case IStatement::SK_BREAK:
                    transpile_break_statement(stat);
                    break;
                case IStatement::SK_CONTINUE:
                    transpile_continue_statement(stat);
                    break;
                case IStatement::SK_RETURN:
                    transpile_return_statement(stat);
                    break;
            }
        }

        void AnyDSL_Transpiler::transpile_compound_statement(const IStatement *stat) {
            const IStatement_compound *sc = as<IStatement_compound>(stat);
            add_to_code("{\n", true);
            indent_level++;
            for (int i = 0; i < sc->get_statement_count(); i++) {

                dispatch_transpile_statement(sc->get_statement(i));
            }
            indent_level--;
            add_to_code("}\n", true);
        }

        void AnyDSL_Transpiler::transpile_return_statement(const IStatement *stat) {
            auto r = as<IStatement_return>(stat);
            add_to_code("", true);
            dispatch_transpile_expression(r->get_expression());
            add_to_code("\n");
        }

        void AnyDSL_Transpiler::transpile_break_statement(const IStatement *stat) {
            add_to_code("break;\n", true);
        }

        void AnyDSL_Transpiler::transpile_do_while_statement(const IStatement *stat) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_expression_statement(const IStatement *stat) {
            const auto *e = as<IStatement_expression>(stat);
            add_to_code("", true);
            dispatch_transpile_expression(e->get_expression());
            add_to_code(";\n");
        }

        void AnyDSL_Transpiler::transpile_switch_statement(const IStatement *stat) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_continue_statement(const IStatement *stat) {
            add_to_code("continue;\n", true);
        }

        void AnyDSL_Transpiler::transpile_for_statement(const IStatement *stat) {
            const IStatement_for *f = as<IStatement_for>(stat);
            add_to_code("{\n", true);
            indent_level++;
            dispatch_transpile_statement(f->get_init());
            add_to_code("{\n", true);
            indent_level++;
            add_to_code("while(", true);
            dispatch_transpile_expression(f->get_condition());
            add_to_code(") {\n");
            indent_level++;
            dispatch_transpile_statement(f->get_body());
            add_to_code("", true);
            dispatch_transpile_expression(f->get_update());
            add_to_code(";\n");
            indent_level--;
            add_to_code("}\n", true);
            indent_level--;
            add_to_code("}\n", true);


            indent_level--;
            add_to_code("}\n", true);
        }

        void AnyDSL_Transpiler::transpile_while_statement(const IStatement *stat) {
            const IStatement_while *w = as<IStatement_while>(stat);
            add_to_code("while(", true);
            dispatch_transpile_expression(w->get_condition());
            add_to_code(") {\n");
            dispatch_transpile_statement(w->get_body());
            add_to_code("}\n", true);
        }

        void AnyDSL_Transpiler::transpile_case_statement(const IStatement *stat) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_if_statement(const IStatement *stat) {
            auto f = as<IStatement_if>(stat);
            add_to_code("if (", true);
            dispatch_transpile_expression(f->get_condition());
            add_to_code(") {\n");
            indent_level++;
            dispatch_transpile_statement(f->get_then_statement());
            indent_level--;
            add_to_code("}", true);
            auto el = f->get_else_statement();
            if (el != nullptr) {
                add_to_code(" else {\n");
                indent_level++;
                dispatch_transpile_statement(f->get_else_statement());
                indent_level--;
                add_to_code("}", true);
            }
            add_to_code("\n");
        }

        void AnyDSL_Transpiler::transpile_declaration_statement(
                const IStatement *stat) {
            add_to_code("", true);
            dispatch_transpile_declaration(
                    as<IStatement_declaration>(stat)->get_declaration());
            add_to_code(";\n");
        }

        void AnyDSL_Transpiler::dispatch_transpile_expression(const IExpression *exp) {
            switch (exp->get_kind()) {
                case IExpression::EK_INVALID:
                    break;
                case IExpression::EK_LITERAL:
                    transpile_expression_literal(exp);
                    break;
                case IExpression::EK_REFERENCE:
                    transpile_expression_reference(exp);
                    break;
                case IExpression::EK_UNARY:
                    transpile_expression_unary(exp);
                    break;
                case IExpression::EK_BINARY:
                    transpile_expression_binary(exp);
                    break;
                case IExpression::EK_CONDITIONAL:
                    transpile_expression_conditional(exp);
                    break;
                case IExpression::EK_CALL:
                    transpile_expression_call(exp);
                    break;
                case IExpression::EK_LET:
                    transpile_expression_let(exp);
                    break;
            }
        }

        const std::string AnyDSL_Transpiler::value_to_string(const IValue *l) {
            auto s = std::string();
            switch (l->get_kind()) {
                case IValue::VK_BAD:
                    break;
                case IValue::VK_BOOL:
                    s = std::to_string(as<IValue_bool>(l)->get_value());
                    break;
                case IValue::VK_INT:
                    s = std::to_string(as<IValue_int>(l)->get_value());
                    break;
                case IValue::VK_ENUM:
                    s = std::to_string(as<IValue_enum>(l)->get_value());
                    break;
                case IValue::VK_FLOAT:
                    s = std::to_string(as<IValue_float>(l)->get_value()) + "f";
                    break;
                case IValue::VK_DOUBLE:
                    s = std::to_string(as<IValue_double>(l)->get_value());
                    break;
                case IValue::VK_STRING:
                    s = (as<IValue_string>(l)->get_value());
                    break;
                case IValue::VK_VECTOR: {
                    s = "[";
                    const auto *v = as<IValue_vector>(l);
                    for (int i = 0; i < v->get_component_count(); i++) {
                        auto saba = v->get_value(i);
                        s += value_to_string(saba);
                        s += ", ";

                    }
                    s += "]";
                    break;
                }
                case IValue::VK_MATRIX:
                    NOT_IMPLEMENTED;
                    // s = std::to_string(as<IValue_matrix>(l)->get_value());
                    break;
                case IValue::VK_ARRAY:
                    NOT_IMPLEMENTED;
                    // s = std::to_string(as<IValue_array>(l)->get_value());
                    break;
                case IValue::VK_RGB_COLOR:
                    s = "[" +
                        std::to_string(as<IValue_rgb_color>(l)->get_value(0)->get_value()) +
                        ", " +
                        std::to_string(as<IValue_rgb_color>(l)->get_value(1)->get_value()) +
                        ", " +
                        std::to_string(as<IValue_rgb_color>(l)->get_value(2)->get_value())
                        + "]";
                    break;
                case IValue::VK_STRUCT: {
                    const auto *v = as<IValue_struct>(l);
                    const auto *st = as<IType_struct>(v->get_type());
                    s = std::string(st->get_symbol()->get_name()) + "{";
                    const ISymbol *sym = nullptr;
                    const IType *type = nullptr;
                    for (int i = 0; i < st->get_field_count(); ++i) {
                        st->get_field(i, type, sym);
                        s += sym->get_name();
                        s += " : ";
                        s += value_to_string(v->get_field(sym));
                        s += ", ";
                    }
                    s += "}";
                    break;
                }
                case IValue::VK_INVALID_REF: {
                    const IType *t = as<IValue_invalid_ref>(l)->get_type();
                    s = std::string(type_to_string(t)) + "()";
                    break;
                }
                case IValue::VK_TEXTURE:
                    // s = std::to_string(as<IValue_texture>(l)->get_value());
                    NOT_IMPLEMENTED;
                    break;
                case IValue::VK_LIGHT_PROFILE:
                    NOT_IMPLEMENTED;
                    s = std::to_string(as<IValue_bool>(l)->get_value());
                    break;
                case IValue::VK_BSDF_MEASUREMENT:
                    NOT_IMPLEMENTED;
                    s = std::to_string(as<IValue_bool>(l)->get_value());
                    break;
            }
            return s;
        }

        void AnyDSL_Transpiler::transpile_expression_literal(
                const IExpression *pExpression) {
            auto l = as<IExpression_literal>(pExpression)->get_value();
            std::string s = std::string();
            switch (l->get_kind()) {
                case IValue::VK_BAD:
                    break;
                case IValue::VK_BOOL:
                    s = std::to_string(as<IValue_bool>(l)->get_value());
                    break;
                case IValue::VK_INT:
                    s = std::to_string(as<IValue_int>(l)->get_value());
                    break;
                case IValue::VK_ENUM:
                    s = std::to_string(as<IValue_enum>(l)->get_value());
                    break;
                case IValue::VK_FLOAT:
                    s = std::to_string(as<IValue_float>(l)->get_value()) + "f";
                    break;
                case IValue::VK_DOUBLE:
                    s = std::to_string(as<IValue_double>(l)->get_value());
                    break;
                case IValue::VK_STRING:
                    s = "\"" + std::string((as<IValue_string>(l)->get_value())) + "\"";
                    break;
                case IValue::VK_VECTOR: {
                    s = "[";
                    const auto *v = as<IValue_vector>(l);
                    for (int i = 0; i < v->get_component_count(); i++) {
                        auto saba = v->get_value(i);
                        if (i != 0) {
                            s += ",";
                        }
                        s += value_to_string(saba);
                    }
                    s += "]";
                    break;
                }
                case IValue::VK_MATRIX: {
                    auto m = as<IValue_matrix>(l);
                    s = "[";
                    for (int i = 0; i < m->get_component_count(); i++) {
                        if (i != 0) {
                            s += ",";
                        }
                        s += value_to_string(m->get_value(i));
                    }
                    s += "]";

                    break;
                }
                case IValue::VK_ARRAY:
                    NOT_IMPLEMENTED;
                    // s = std::to_string(as<IValue_array>(l)->get_value());
                    break;
                case IValue::VK_RGB_COLOR:
                    s = "[" +
                        std::to_string(as<IValue_rgb_color>(l)->get_value(0)->get_value()) +
                        ", " +
                        std::to_string(as<IValue_rgb_color>(l)->get_value(1)->get_value()) +
                        ", " +
                        std::to_string(as<IValue_rgb_color>(l)->get_value(2)->get_value())
                        + "]";
                    break;
                case IValue::VK_STRUCT: {
                    const auto *v = as<IValue_struct>(l);
                    const auto *st = as<IType_struct>(v->get_type());
                    s = std::string(st->get_symbol()->get_name()) + "{\n";
                    indent_level++;
                    const ISymbol *sym = nullptr;
                    const IType *type = nullptr;
                    for (int i = 0; i < st->get_field_count(); ++i) {
                        st->get_field(i, type, sym);
                        s += indent_code(sym->get_name());
                        s += " : ";
                        s += value_to_string(v->get_field(sym));
                        s += ",\n";
                    }
                    indent_level--;
                    s += indent_code("}");
                    break;
                }
                case IValue::VK_INVALID_REF:
                    break;
                case IValue::VK_TEXTURE: {
                    s = "texture";
                    break;
                }
                case IValue::VK_LIGHT_PROFILE:
                    NOT_IMPLEMENTED;
                    s = std::to_string(as<IValue_bool>(l)->get_value());
                    break;
                case IValue::VK_BSDF_MEASUREMENT:
                    s = "bsdf_measurement";
                    break;
            }
            add_to_code(s);
        }

        void AnyDSL_Transpiler::transpile_expression_let(
                const IExpression *pExpression) {
            const auto *l = as<IExpression_let>(pExpression);

            for (int i = 0; i < l->get_declaration_count(); i++) {
                dispatch_transpile_declaration(l->get_declaration(i));
                add_to_code(";");
            }
            add_to_code("\n");
            add_to_code("{\n", true);
            indent_level++;
            add_to_code("", true);
            dispatch_transpile_expression(l->get_expression());
            add_to_code("\n");
            indent_level--;
            add_to_code("}", true);
        }

        void AnyDSL_Transpiler::transpile_expression_conditional(
                const IExpression *pExpression) {
            auto conditional = as<IExpression_conditional>(pExpression);
            add_to_code("if (");
            dispatch_transpile_expression(conditional->get_condition());
            add_to_code(") {");
            dispatch_transpile_expression(conditional->get_true());
            add_to_code("} else {");
            dispatch_transpile_expression(conditional->get_false());
            add_to_code("}");
        }

        void AnyDSL_Transpiler::transpile_expression_unary(
                const IExpression *pExpression) {
            auto un = as<IExpression_unary>(pExpression);

            add_to_code(unary_operator_to_string(un->get_operator()));
            add_to_code("__");
            add_to_code(type_to_string(un->get_argument()->get_type()));
            add_to_code("(");
            dispatch_transpile_expression(un->get_argument());
            add_to_code(")");

        }

        void AnyDSL_Transpiler::transpile_expression_reference(
                const IExpression *pExpression) {
            const IExpression_reference *ref = as<IExpression_reference>(pExpression);
            add_to_code(ref->get_definition()->get_symbol()->get_name());
        }

        void AnyDSL_Transpiler::transpile_expression_binary(
                const IExpression *pExpression) {
            auto bin = as<IExpression_binary>(pExpression);
            switch (bin->get_operator()) {

                case IExpression_binary::OK_SELECT:
                    dispatch_transpile_expression(bin->get_left_argument());
                    add_to_code(".");
                    dispatch_transpile_expression(bin->get_right_argument());
                    break;

                default:
                    add_to_code(binary_operator_to_string(bin->get_operator()));
                    add_to_code("__");
                    add_to_code(type_to_string(bin->get_left_argument()->get_type()));
                    add_to_code("_");
                    add_to_code(type_to_string(bin->get_right_argument()->get_type()));
                    add_to_code("(");
                    dispatch_transpile_expression(bin->get_left_argument());
                    add_to_code(", ");
                    dispatch_transpile_expression(bin->get_right_argument());
                    add_to_code(")");


            }
        }

        void AnyDSL_Transpiler::transpile_expression_call(
                const IExpression *pExpression) {
            const auto *c = as<IExpression_call>(pExpression);
            auto calle = as<IExpression_reference>(c->get_reference());
            auto calle_name = calle->get_name()
                    ->get_qualified_name()
                    ->get_definition()
                    ->get_symbol()
                    ->get_name();
            add_to_code(calle_name);
            add_to_code("_");
            for (int i = 0; i < c->get_argument_count(); ++i) {
                const IArgument *arg = c->get_argument(i);
                const IExpression *exp = arg->get_argument_expr();
                add_to_code("_");
                add_to_code(type_to_string_for_mangling(exp->get_type()));
            }
            add_to_code("(");

            for (int i = 0; i < c->get_argument_count(); ++i) {
                const IArgument *arg = c->get_argument(i);
                const IExpression *exp = arg->get_argument_expr();
                dispatch_transpile_expression(exp);
                add_to_code(", ");
            }
            add_to_code(")");
        }

        const std::string AnyDSL_Transpiler::binary_operator_to_string(
                const IExpression_binary::Operator op) {
            switch (op) {
                case IExpression_binary::OK_SELECT:
                    return ".";
                case IExpression_binary::OK_ARRAY_INDEX:
                    return "array_index";
                case IExpression_binary::OK_MULTIPLY:
                    return "mul";
                case IExpression_binary::OK_DIVIDE:
                    return "div";
                case IExpression_binary::OK_MODULO:
                    return "mod";
                case IExpression_binary::OK_PLUS:
                    return "add";
                case IExpression_binary::OK_MINUS:
                    return "sub";
                case IExpression_binary::OK_SHIFT_LEFT:
                    return "shiftl";
                case IExpression_binary::OK_SHIFT_RIGHT:
                    return "shiftr";
                case IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT:
                    return "ushiftr";
                case IExpression_binary::OK_LESS:
                    return "le";
                case IExpression_binary::OK_LESS_OR_EQUAL:
                    return "leq";
                case IExpression_binary::OK_GREATER_OR_EQUAL:
                    return "geq";
                case IExpression_binary::OK_GREATER:
                    return "ge";
                case IExpression_binary::OK_EQUAL:
                    return "eq";
                case IExpression_binary::OK_NOT_EQUAL:
                    return "neq";
                case IExpression_binary::OK_BITWISE_AND:
                    return "bit_and";
                case IExpression_binary::OK_BITWISE_XOR:
                    return "bit_xor";
                case IExpression_binary::OK_BITWISE_OR:
                    return "bit_or";
                case IExpression_binary::OK_LOGICAL_AND:
                    return "and";
                case IExpression_binary::OK_LOGICAL_OR:
                    return "or";
                case IExpression_binary::OK_ASSIGN:
                    return "assign";
                case IExpression_binary::OK_MULTIPLY_ASSIGN:
                    return "mul_assign";
                case IExpression_binary::OK_DIVIDE_ASSIGN:
                    return "div_assign";
                case IExpression_binary::OK_MODULO_ASSIGN:
                    return "mod_assign";
                case IExpression_binary::OK_PLUS_ASSIGN:
                    return "add_assign";
                case IExpression_binary::OK_MINUS_ASSIGN:
                    return "sub_assign";
                case IExpression_binary::OK_SHIFT_LEFT_ASSIGN:
                    return "shiftl_assign";
                case IExpression_binary::OK_SHIFT_RIGHT_ASSIGN:
                    return "shiftr_assign";
                case IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT_ASSIGN:
                    return "ushiftr_assign";
                case IExpression_binary::OK_BITWISE_AND_ASSIGN:
                    return "bit_and_assign";
                case IExpression_binary::OK_BITWISE_XOR_ASSIGN:
                    return "bit_xor_assign";
                case IExpression_binary::OK_BITWISE_OR_ASSIGN:
                    return "bit_or_assign";
                case IExpression_binary::OK_SEQUENCE:
                    return "..";
            }
        }

        const std::string AnyDSL_Transpiler::unary_operator_to_string(
                const IExpression_unary::Operator op) {
            switch (op) {
                case IExpression_unary::OK_BITWISE_COMPLEMENT:
                    return "bit_comp";
                case IExpression_unary::OK_LOGICAL_NOT:
                    return "log_not";
                case IExpression_unary::OK_POSITIVE:
                    return "pos";
                case IExpression_unary::OK_NEGATIVE:
                    return "neg";
                case IExpression_unary::OK_PRE_INCREMENT:
                    return "pre_inc";
                case IExpression_unary::OK_PRE_DECREMENT:
                    return "pre_dec";
                case IExpression_unary::OK_POST_INCREMENT:
                    return "post_inc";
                case IExpression_unary::OK_POST_DECREMENT:
                    return "post_dec";
            }
        }

        bool AnyDSL_Transpiler::is_prefix_operator(const IExpression_unary::Operator op) {
            switch (op) {
                case IExpression_unary::OK_BITWISE_COMPLEMENT:
                case IExpression_unary::OK_LOGICAL_NOT:
                case IExpression_unary::OK_POSITIVE:
                case IExpression_unary::OK_NEGATIVE:
                case IExpression_unary::OK_PRE_INCREMENT:
                case IExpression_unary::OK_PRE_DECREMENT:
                    return true;
                case IExpression_unary::OK_POST_INCREMENT:
                case IExpression_unary::OK_POST_DECREMENT:
                    return false;
            }
        }

        void AnyDSL_Transpiler::add_to_code(const std::string &str, bool do_indent) {
            assert(indent_level >= 0);
            if (do_indent) {
                for (int i = 0; i < indent_level; i++) {
                    out += indent;
                }
            }

            out += str;
        }

        std::string AnyDSL_Transpiler::indent_code(const std::string &str) {
            assert(indent_level >= 0);
            std::string s = "";
            for (int i = 0; i < indent_level; i++) {
                s += indent;
            }
            s += str;
            return s;
        }
    } // namespace mdl

} // namespace mi
