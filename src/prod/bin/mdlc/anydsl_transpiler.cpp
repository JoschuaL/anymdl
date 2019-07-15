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
            imports.insert(module->get_name());
            for (int i = 0; i < module->get_import_count(); i++) {
                const IModule *m = module->get_import(i);
                if (imports.find(std::string(m->get_name())) != imports.end()) {
                    continue;
                }
                imports.insert(std::string(m->get_name()));
                transpile_module(m);

            }

            for (int j = 0; j < module->get_builtin_definition_count(); ++j) {
                IDefinition const *def = module->get_builtin_definition(j);
                dispatch_transpile_definition(def);
            }

            for (int i = 0, n = module->get_exported_definition_count(); i < n; ++i) {
                IDefinition const *def = module->get_exported_definition(i);
                dispatch_transpile_definition(def);
            }





            /*for (int i = 0; i < module->get_declaration_count(); i++) {
                const IDeclaration *decl = module->get_declaration(i);
                dispatch_transpile_declaration(decl);
            }*/

            /*for (int i = 0; i < module->get_builtin_definition_count(); i++) {
                const IDefinition *def = module->get_builtin_definition(i);
                dispatch_transpile_definition(def);
            }*/
            size_t index = 0;
            while (true) {
                /* Locate the substring to replace. */
                index = this->out.find("ENUM+DELIMITER+STRING", index);
                if (index == std::string::npos) break;

                /* Make the replacement. */
                this->out.replace(index, std::string("ENUM+DELIMITER+STRING").size(), "::");

                /* Advance index forward so the next iteration doesn't pick it up as well. */
                index += 2;
            }
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
            add_to_code(type_to_string_for_mangling(definition->get_type(), false));
            add_to_code(" = ");
            add_to_code(value_to_string(definition->get_constant_value()));
            add_to_code(";\n");
        }

        void AnyDSL_Transpiler::transpile_enum_value(const IDefinition *definition) { NOT_IMPLEMENTED; }

        void AnyDSL_Transpiler::transpile_annotation(const IDefinition *definition) { return; }

        void AnyDSL_Transpiler::transpile_type(const IDefinition *definition) {
            auto t = definition->get_type()->get_kind();
            switch (t) {
                case IType::TK_ENUM:
                    add_to_code("type ", true);
                    add_to_code(definition->get_symbol()->get_name());
                    add_to_code(" = int;\n");
                    if (definition->get_declaration() != nullptr) {
                        dispatch_transpile_declaration(definition->get_declaration());
                    }
                    return;
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
                case IType::TK_ALIAS:
                    add_to_code("type ");
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
            auto fname = std::string(definition->get_symbol()->get_name());
            const IType_function *fun_type = as<IType_function>(definition->get_type());
            int parameter_count = fun_type->get_parameter_count();
            std::vector<std::string> argument_types = std::vector<std::string>(parameter_count);
            std::vector<std::string> argument_names = std::vector<std::string>(parameter_count);
            std::vector<std::string> argument_types_mangling = std::vector<std::string>(parameter_count);
            bool is_stateless = is_stateless_return_type(fun_type->get_return_type());

            for (int k = 0; k < parameter_count; ++k) {
                IType const *parameter_type = nullptr;
                ISymbol const *parameter_symbol = nullptr;

                fun_type->get_parameter(k, parameter_type, parameter_symbol);

                argument_types_mangling[k] = type_to_string_for_mangling(parameter_type, true);
                argument_types[k] = is_stateless ? type_to_string_closure(parameter_type) : type_to_string_for_mangling(
                        parameter_type, false);

                argument_names[k] = parameter_symbol->get_name();
            }

            add_to_code("fn @", true);
            add_to_code(fname);
            add_to_code("_");
            for (int i = 0; i < argument_types.size(); i++) {
                add_to_code("_");
                add_to_code(argument_types_mangling[i]);
            }
            if (!is_stateless) {
                add_to_code("_State");
            }
            add_to_code("_mdl_math(");
            for (int i = 0; i < argument_names.size(); i++) {
                add_to_code(argument_names[i]);
                add_to_code(" : ");
                add_to_code(argument_types[i]);
                add_to_code(", ");
            }
            if (!is_stateless) {
                add_to_code(" state : State,");
            }

            add_to_code(" math : mdl_math");
            add_to_code(") -> ");

            add_to_code(type_to_string_for_mangling(fun_type->get_return_type(), false));


            if (definition->get_declaration() != nullptr) {
                dispatch_transpile_declaration(definition->get_declaration());
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

        void AnyDSL_Transpiler::transpile_member(const IDefinition *definition) { UNREACHABLE; }

        void AnyDSL_Transpiler::transpile_parameter(const IDefinition *definition) { UNREACHABLE; }

        void AnyDSL_Transpiler::transpile_array_size(const IDefinition *definition) { UNREACHABLE; }

        void AnyDSL_Transpiler::transpile_variable(const IDefinition *definition) {
            add_to_code("let mut ", true);
            add_to_code(definition->get_symbol()->get_name());
            add_to_code(" : ");
            add_to_code(type_to_string_for_mangling(definition->get_type(), false));
            if (definition->get_declaration() != nullptr) {
                add_to_code(" = ");
                dispatch_transpile_declaration(definition->get_declaration());
            }

            add_to_code(";\n");
        }

        const std::string AnyDSL_Transpiler::type_to_string_closure(const IType *type) {
            return "fn(State) -> " + type_to_string_for_mangling(type, false);
        }

        const std::string
        AnyDSL_Transpiler::type_to_string_for_mangling(const IType *type, bool no_special_characters) {
            std::string ts;
            switch (type->get_kind()) {
                case IType::TK_ALIAS: {
                    const IType_alias *t = as<IType_alias>(type);
                    ts = type_to_string_for_mangling(t->get_aliased_type(), no_special_characters);
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
                    ts = type_to_string_for_mangling(t->get_element_type(), no_special_characters) +
                         std::to_string(t->get_size());
                    break;
                }
                case IType::TK_MATRIX: {
                    const IType_matrix *t = as<IType_matrix>(type);
                    const IType_vector *v = as<IType_vector>(t->get_element_type());
                    ts = type_to_string_for_mangling(v->get_element_type(), no_special_characters) +
                         std::to_string(t->get_columns()) + "x" +
                         std::to_string(v->get_compound_size());
                    break;
                }

                case IType::TK_ARRAY: {
                    const IType_array *t = as<IType_array>(type);
                    auto str = std::string();
                    if (!no_special_characters) {
                        str += "[";
                    }
                    str += (type_to_string_for_mangling(t->get_element_type(), no_special_characters));
                    if (no_special_characters) {
                        str += "_arr";
                    } else {
                        if (t->get_size() >= 0) {
                            str += "*";
                        }
                    }
                    if (t->get_size() >= 0) {
                        str += std::to_string(t->get_size());
                    }
                    if (!no_special_characters) {
                        str += "]";
                    }
                    ts = str;
                    break;
                }

                case IType::TK_COLOR:
                    ts = "color";
                    break;
                case IType::TK_FUNCTION: {
                    const auto *t = as<IType_function>(type);
                    auto str = std::string();
                    const IType *itype;
                    const ISymbol *iSymbol;
                    if (!no_special_characters) {
                        str += "fn(";
                        for (int i = 0; i < t->get_parameter_count(); i++) {
                            if (i != 0) {
                                str += ",";
                            }
                            t->get_parameter(i, itype, iSymbol);
                            str += type_to_string_for_mangling(itype, no_special_characters);
                        }
                        str += ") -> ";
                        str += type_to_string_for_mangling(t->get_return_type(), no_special_characters);
                        ts = str;
                        break;
                    } else {
                        str += "fn__";
                        for (int i = 0; i < t->get_parameter_count(); i++) {
                            if (i != 0) {
                                str += "_";
                            }
                            t->get_parameter(i, itype, iSymbol);
                            str += type_to_string_for_mangling(itype, no_special_characters);
                        }
                        str += "_to_";
                        str += type_to_string_for_mangling(t->get_return_type(), no_special_characters);
                        ts = str;
                        break;
                    }

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
            unsigned long abs_path = ts.find("::");
            while (abs_path != std::string::npos) {
                ts = ts.substr(abs_path + 2);
                abs_path = ts.find("::");
            }
            return ts;
        }

        void AnyDSL_Transpiler::dispatch_transpile_declaration(const IDeclaration *decl) {
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

        void AnyDSL_Transpiler::transpile_function_declaration(const IDeclaration *pDeclaration) {
            auto *d = as<IDeclaration_function>(pDeclaration);

            const IStatement *s = d->get_body();

            if (s != nullptr) {
                bool is_compound = s->get_kind() == IStatement::Kind::SK_COMPOUND;

                if (!is_compound) {
                    add_to_code(" {\n");
                    indent_level++;
                }
                dispatch_transpile_statement(s);
                if (!is_compound) {
                    indent_level--;
                    add_to_code("}\n\n", true);
                    size_t index = this->out.rfind(";");
                    this->out.erase(index, 1);
                } else {
                    add_to_code("\n");
                }
            } else {
                add_to_code("{}\n\n");
            }
        }

        void AnyDSL_Transpiler::transpile_import(const IDeclaration *decl) {
            return;
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_type_alias(const IDeclaration *decl) {
            const IDeclaration_type_alias *ta = as<IDeclaration_type_alias>(decl);
            add_to_code(" = ");
            add_to_code(type_to_string_for_mangling(ta->get_type_name()->get_type(), false));
            add_to_code(";\n\n");
        }

        void AnyDSL_Transpiler::transpile_struct(const IDeclaration *decl) {
            const IDeclaration_type_struct *s = as<IDeclaration_type_struct>(decl);
            add_to_code(" {\n");
            indent_level++;
            for (int i = 0; i < s->get_field_count(); i++) {
                add_to_code(s->get_field_name(i)->get_symbol()->get_name(), true);
                add_to_code(": ");
                add_to_code(type_to_string_for_mangling(s->get_field_type_name(i)->get_type(), false));
                add_to_code(",\n");
            }
            indent_level--;
            add_to_code("}\n\n", true);
            add_to_code("fn @", true);
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code("_");
            for (int i = 0; i < s->get_field_count(); i++) {
                add_to_code("_");
                add_to_code(type_to_string_for_mangling(s->get_field_type_name(i)->get_type(), true));
            }

            add_to_code("_mdl_math(");
            for (int i = 0; i < s->get_field_count(); i++) {
                add_to_code(s->get_field_name(i)->get_symbol()->get_name(), true);
                add_to_code(": ");
                add_to_code(type_to_string_for_mangling(s->get_field_type_name(i)->get_type(), false));
                add_to_code(", ");
            }
            add_to_code("math: mdl_math) -> ");
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code(" {\n");
            indent_level++;
            add_to_code("", true);
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code("{\n");
            indent_level++;
            for (int i = 0; i < s->get_field_count(); i++) {
                add_to_code(s->get_field_name(i)->get_symbol()->get_name(), true);
                add_to_code(": ");
                add_to_code(s->get_field_name(i)->get_symbol()->get_name());
                add_to_code(",\n");
            }
            indent_level--;
            add_to_code("}\n", true);
            indent_level--;
            add_to_code("}\n", true);

            add_to_code("fn @", true);
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code("__");
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code("_mdl_math");
            add_to_code("(copy:  ");
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code(", math: mdl_math) -> ");
            add_to_code(s->get_name()->get_symbol()->get_name());
            add_to_code(" {\n");
            indent_level++;
            add_to_code("", true);
            add_to_code(s->get_name()->get_symbol()->get_name());
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

            for (int i = 0; i < e->get_value_count(); i++) {
                add_to_code("static ", true);
                add_to_code(e->get_definition()->get_symbol()->get_name());
                add_to_code("_");
                add_to_code(e->get_value_name(i)->get_symbol()->get_name());
                add_to_code(" : int = ");
                if(e->get_value_init(i) != nullptr){
                    dispatch_transpile_expression(e->get_value_init(i), false);
                } else {
                   add_to_code(std::to_string(i));
                }

                add_to_code(";\n");
            }


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

                add_to_code(type_to_string_for_mangling(v->get_type_name()->get_type(), false));

                if (v->get_variable_init(i) != nullptr) {
                    add_to_code(" = ");
                    dispatch_transpile_expression(v->get_variable_init(i), false);
                }


            }
        }

        void AnyDSL_Transpiler::transpile_constant_declaration(const IDeclaration *decl) {
            const IDeclaration_constant *c = as<IDeclaration_constant>(decl);
            for (int i = 0; i < c->get_constant_count(); i++) {
                add_to_code("static ", true);
                add_to_code(c->get_constant_name(i)->get_symbol()->get_name());
                add_to_code(": ");
                add_to_code(type_to_string_for_mangling(c->get_type_name()->get_type(), false));
                if (c->get_constant_exp(i) != nullptr) {
                    add_to_code(" = ");
                    dispatch_transpile_expression(c->get_constant_exp(i), false);
                }
                add_to_code(";\n");
            }
        }

        void AnyDSL_Transpiler::transpile_annotation_declaration(const IDeclaration *decl) { return; }

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
            add_to_code("return(", true);
            dispatch_transpile_expression(r->get_expression(), false);
            add_to_code(")\n");
        }

        void AnyDSL_Transpiler::transpile_break_statement(const IStatement *stat) {
            add_to_code("break()\n", true);
        }

        void AnyDSL_Transpiler::transpile_do_while_statement(const IStatement *stat) {
            const IStatement_do_while *dw = as<IStatement_do_while>(stat);
            add_to_code("while {\n", true);
            indent_level++;
            dispatch_transpile_statement(dw->get_body());
            add_to_code("", true);
            dispatch_transpile_expression(dw->get_condition(), false);
            indent_level--;
            add_to_code("\n");
            add_to_code("} {}\n", true);

        }

        void AnyDSL_Transpiler::transpile_expression_statement(const IStatement *stat) {
            const auto *e = as<IStatement_expression>(stat);
            add_to_code("", true);
            dispatch_transpile_expression(e->get_expression(), false);

            add_to_code(";\n");


        }

        void AnyDSL_Transpiler::transpile_switch_statement(const IStatement *stat) {
            const IStatement_switch *sw = as<IStatement_switch>(stat);
            add_to_code("while(true) {\n", true);
            indent_level++;
            add_to_code("let switch_condition = ", true);
            dispatch_transpile_expression(sw->get_condition(), false);
            add_to_code(";\n");
            add_to_code("let mut fallthrough: bool = false;\n", true);
            for (int i = 0; i < sw->get_case_count(); ++i) {
                dispatch_transpile_statement(sw->get_case(i));
            }
            add_to_code("break()\n", true);
            indent_level--;
            add_to_code("}\n", true);
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
            dispatch_transpile_expression(f->get_condition(), false);
            add_to_code(") {\n");
            indent_level++;
            dispatch_transpile_statement(f->get_body());
            add_to_code("", true);
            dispatch_transpile_expression(f->get_update(), false);
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
            dispatch_transpile_expression(w->get_condition(), false);
            add_to_code(") {\n");
            indent_level++;
            dispatch_transpile_statement(w->get_body());
            indent_level--;
            add_to_code("}\n", true);
        }

        void AnyDSL_Transpiler::transpile_case_statement(const IStatement *stat) {
            const IStatement_case *c = as<IStatement_case>(stat);

            if (c->get_label() != nullptr) {
                add_to_code("if(fallthrough || switch_condition == ", true);
                dispatch_transpile_expression(c->get_label(), false);
                add_to_code("){\n");
                indent_level++;
                add_to_code("fallthrough = true;\n", true);
                for (int i = 0; i < c->get_statement_count(); ++i) {
                    dispatch_transpile_statement(c->get_statement(i));
                }
                indent_level--;
                add_to_code("}\n", true);
            } else {
                for (int i = 0; i < c->get_statement_count(); ++i) {
                    dispatch_transpile_statement(c->get_statement(i));
                }
            }


        }

        void AnyDSL_Transpiler::transpile_if_statement(const IStatement *stat) {
            auto f = as<IStatement_if>(stat);
            add_to_code("if (", true);
            dispatch_transpile_expression(f->get_condition(), false);
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

        void AnyDSL_Transpiler::transpile_declaration_statement(const IStatement *stat) {
            add_to_code("", true);
            dispatch_transpile_declaration(as<IStatement_declaration>(stat)->get_declaration());
            add_to_code(";\n");
        }

        void AnyDSL_Transpiler::dispatch_transpile_expression(const IExpression *exp, bool closure) {
            switch (exp->get_kind()) {
                case IExpression::EK_INVALID:
                    break;
                case IExpression::EK_LITERAL:
                    transpile_expression_literal(exp, closure);
                    break;
                case IExpression::EK_REFERENCE:
                    transpile_expression_reference(exp, closure);
                    break;
                case IExpression::EK_UNARY:
                    transpile_expression_unary(exp, closure);
                    break;
                case IExpression::EK_BINARY:
                    transpile_expression_binary(exp, closure);
                    break;
                case IExpression::EK_CONDITIONAL:
                    transpile_expression_conditional(exp, closure);
                    break;
                case IExpression::EK_CALL:
                    transpile_expression_call(exp, closure);
                    break;
                case IExpression::EK_LET:
                    transpile_expression_let(exp, closure);
                    break;
            }
        }

        const std::string AnyDSL_Transpiler::value_to_string(const IValue *l) {
            auto s = std::string();
            switch (l->get_kind()) {
                case IValue::VK_BAD:
                    break;
                case IValue::VK_BOOL:

                    s = as<IValue_bool>(l)->get_value() ? "true" : "false";
                    break;
                case IValue::VK_INT:
                    s = std::to_string(as<IValue_int>(l)->get_value());
                    break;
                case IValue::VK_ENUM: {
                    const IValue_enum *ve = as<IValue_enum>(l);
                    const IType_enum *en = ve->get_type();
                    const ISymbol *sym = nullptr;
                    int code = 0;
                    en->get_value(ve->get_index(), sym, code);
                    s = std::string(en->get_symbol()->get_name()) + "_" +
                        std::string(sym->get_name());
                }
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
                    const IValue_vector *v = as<IValue_vector>(l);
                    s = "make_";
                    s += type_to_string_for_mangling(v->get_type(), true);
                    s += "(";
                    for (int i = 0; i < v->get_component_count(); i++) {
                        auto saba = v->get_value(i);
                        s += value_to_string(saba);
                        s += ", ";
                    }
                    s += ")";
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
                case IValue::VK_ARRAY: {
                    s = "[";
                    const auto *v = as<IValue_array>(l);
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
                case IValue::VK_RGB_COLOR: {
                    const IValue_rgb_color *v = as<IValue_rgb_color>(l);
                    s = "make_color(";
                    for (int i = 0; i < v->get_component_count(); i++) {
                        auto saba = v->get_value(i);
                        s += value_to_string(saba);
                        s += ", ";
                    }
                    s += ")";
                    break;
                }
                case IValue::VK_STRUCT: {
                    const IValue_struct *v = as<IValue_struct>(l);
                    const IType_struct *st = as<IType_struct>(v->get_type());
                    bool is_stateless = is_stateless_return_type(v->get_type());
                    s = std::string(st->get_symbol()->get_name()) + "_";
                    const ISymbol *sym = nullptr;
                    const IType *type = nullptr;
                    for (int i = 0; i < st->get_field_count(); ++i) {
                        st->get_field(i, type, sym);
                        s += "_";
                        s += type_to_string_for_mangling(type, true);
                    }
                    s += "_mdl_math(\n";
                    indent_level++;
                    for (int i = 0; i < st->get_field_count(); ++i) {
                        st->get_field(i, type, sym);
                        s += indent_code("");
                        if (is_stateless) {
                            s += "|state:State|{";
                        }
                        while (type->get_kind() == IType::Kind::TK_ALIAS) {
                            type = as<IType_alias>(type)->get_aliased_type();
                        }

                        s += (value_to_string(v->get_field(sym)));


                        if (is_stateless) {
                            s += "}";
                        }
                        s += ",\n";
                    }
                    s += indent_code("math\n");
                    indent_level--;
                    s += indent_code(")");
                    break;
                }
                case IValue::VK_INVALID_REF: {
                    const IType *t = as<IValue_invalid_ref>(l)->get_type();
                    s = std::string(type_to_string_for_mangling(t, true)) + "__mdl_math(math)";
                    break;
                }
                case IValue::VK_TEXTURE:
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
            unsigned long abs_path = s.find("::");
            while (abs_path != std::string::npos) {
                s = s.substr(abs_path + 2);
                abs_path = s.find("::");
            }

            return s;
        }

        void AnyDSL_Transpiler::transpile_expression_literal(const IExpression *pExpression, bool closure) {
            auto l = as<IExpression_literal>(pExpression)->get_value();

            add_to_code(value_to_string(l));
        }

        void AnyDSL_Transpiler::transpile_expression_let(const IExpression *pExpression, bool closure) {
            const auto *l = as<IExpression_let>(pExpression);

            for (int i = 0; i < l->get_declaration_count(); i++) {
                if (i > 0) {
                    add_to_code("", true);
                }
                const IDeclaration *decl = l->get_declaration(i);
                if (decl->get_kind() == IDeclaration::Kind::DK_VARIABLE) {

                    const IDeclaration_variable *var_decl = as<IDeclaration_variable>(decl);
                    const IType *t = var_decl->get_type_name()->get_type();
                    bool is_stateless = is_stateless_return_type(t);
                    std::string var_type = is_stateless ? type_to_string_for_mangling(t, false)
                                                        : type_to_string_closure(t);
                    for (int j = 0; j < var_decl->get_variable_count(); ++j) {
                        if (j > 0) {
                            add_to_code("", true);
                        }
                        add_to_code("let ");
                        add_to_code(var_decl->get_variable_name(j)->get_symbol()->get_name());
                        add_to_code(": ");
                        add_to_code(var_type);
                        add_to_code(" = ");
                        if (!is_stateless) {
                            add_to_code("|state:State|{");
                        }
                        dispatch_transpile_expression(var_decl->get_variable_init(j), true);
                        if (!is_stateless) {
                            add_to_code("}");
                        }
                        add_to_code(";\n");

                    }
                } else {
                    dispatch_transpile_declaration(l->get_declaration(i));
                    add_to_code(";\n");
                }

            }
            add_to_code("{\n", true);
            indent_level++;
            add_to_code("", true);
            dispatch_transpile_expression(l->get_expression(), false);
            add_to_code("\n");
            indent_level--;
            add_to_code("}\n", true);
        }

        void AnyDSL_Transpiler::transpile_expression_conditional(const IExpression *pExpression, bool closure) {
            auto conditional = as<IExpression_conditional>(pExpression);
            add_to_code("if (");
            dispatch_transpile_expression(conditional->get_condition(), closure);
            add_to_code(") {");
            dispatch_transpile_expression(conditional->get_true(), closure);
            add_to_code("} else {");
            dispatch_transpile_expression(conditional->get_false(), closure);
            add_to_code("}");
        }

        void AnyDSL_Transpiler::transpile_expression_unary(const IExpression *pExpression, bool closure) {
            auto un = as<IExpression_unary>(pExpression);

            add_to_code(unary_operator_to_string(un->get_operator()));
            add_to_code("__");
            add_to_code(type_to_string_for_mangling(un->get_argument()->get_type(), true));
            add_to_code("_mdl_math(");
            if (is_assign_operator(un->get_operator())) {
                add_to_code("&mut ");
            }
            dispatch_transpile_expression(un->get_argument(), closure);
            add_to_code(", math)");
        }

        void AnyDSL_Transpiler::transpile_expression_reference(const IExpression *pExpression, bool closure) {
            const IExpression_reference *ref = as<IExpression_reference>(pExpression);
            add_to_code(ref->get_definition()->get_symbol()->get_name());
            if (closure && !is_stateless_return_type(ref->get_type())) {
                add_to_code("(state)");
            }
        }

        void AnyDSL_Transpiler::transpile_expression_binary(const IExpression *pExpression, bool closure) {
            auto bin = as<IExpression_binary>(pExpression);
            if (is_shorthand_assign_operator(bin->get_operator())) {
                dispatch_transpile_expression(bin->get_left_argument(), closure);
                add_to_code(" = ");
                add_to_code(binary_operator_to_string(get_shorthand_operator(bin->get_operator())));
                add_to_code("__");
                add_to_code(type_to_string_for_mangling(bin->get_left_argument()->get_type(), true));
                add_to_code("_");
                add_to_code(type_to_string_for_mangling(bin->get_right_argument()->get_type(), true));
                add_to_code("_mdl_math(\n");
                indent_level++;
                add_to_code("", true);

                dispatch_transpile_expression(bin->get_left_argument(), closure);


                add_to_code(",\n");
                add_to_code("", true);
                dispatch_transpile_expression(bin->get_right_argument(), closure);
                add_to_code(",\n");
                add_to_code("", true);
                add_to_code("math");
                add_to_code("\n");
                indent_level--;
                add_to_code(")", true);


            } else {
                switch (bin->get_operator()) {
                    case IExpression_binary::OK_SELECT:
                        dispatch_transpile_expression(bin->get_left_argument(), closure);
                        add_to_code(".");
                        dispatch_transpile_expression(bin->get_right_argument(), false);
                        break;
                    case IExpression_binary::OK_ARRAY_INDEX:
                        if (bin->get_left_argument()->get_type()->get_kind() == IType::Kind::TK_VECTOR ||
                            bin->get_left_argument()->get_type()->get_kind() == IType::Kind::TK_MATRIX) {
                            add_to_code(
                                    type_to_string_for_mangling(bin->get_left_argument()->get_type(), true) + "_get(");
                            dispatch_transpile_expression(bin->get_left_argument(), closure);
                            add_to_code(", ");
                            dispatch_transpile_expression(bin->get_right_argument(), closure);
                            add_to_code(")");
                        } else {
                            dispatch_transpile_expression(bin->get_left_argument(), closure);
                            add_to_code("(");
                            dispatch_transpile_expression(bin->get_right_argument(), closure);
                            add_to_code(")");
                        }
                        break;
                    case IExpression_binary::OK_ASSIGN: {
                        dispatch_transpile_expression(bin->get_left_argument(), closure);
                        add_to_code(" = ");
                        if (bin->get_left_argument()->get_type()->skip_type_alias()->get_kind() ==
                            IType::Kind::TK_VECTOR &&
                            bin->get_right_argument()->get_type()->skip_type_alias()->get_kind() !=
                            IType::Kind::TK_VECTOR) {
                            add_to_code(type_to_string_for_mangling(bin->get_left_argument()->get_type(), true));
                            add_to_code("__");
                            add_to_code(type_to_string_for_mangling(bin->get_right_argument()->get_type(), true));
                            add_to_code("(");
                            dispatch_transpile_expression(bin->get_right_argument(), closure);
                            add_to_code(")");

                        } else {
                            dispatch_transpile_expression(bin->get_right_argument(), closure);
                        }
                    }
                        break;
                    case IExpression_binary::OK_SEQUENCE:{
                        dispatch_transpile_expression(bin->get_left_argument(), closure);
                        add_to_code(";\n");
                        add_to_code("", true);
                        dispatch_transpile_expression(bin->get_right_argument(), closure);
                        break;
                    }
                    default:
                        add_to_code(binary_operator_to_string(bin->get_operator()));
                        add_to_code("__");
                        add_to_code(type_to_string_for_mangling(bin->get_left_argument()->get_type(), true));
                        add_to_code("_");
                        add_to_code(type_to_string_for_mangling(bin->get_right_argument()->get_type(), true));
                        add_to_code("_mdl_math(\n");
                        indent_level++;
                        add_to_code("", true);

                        dispatch_transpile_expression(bin->get_left_argument(), closure);


                        add_to_code(",\n");
                        add_to_code("", true);
                        dispatch_transpile_expression(bin->get_right_argument(), closure);
                        add_to_code(",\n");
                        add_to_code("", true);
                        add_to_code("math");
                        add_to_code("\n");
                        indent_level--;
                        add_to_code(")", true);
                }
            }

        }

        void AnyDSL_Transpiler::transpile_expression_call(const IExpression *pExpression, bool closure) {
            const auto *c = as<IExpression_call>(pExpression);
            auto callee = as<IExpression_reference>(c->get_reference());
            const IDefinition *callee_def =
                    callee->get_definition() == nullptr ? callee->get_name()->get_qualified_name()->get_definition()
                                                        : callee->get_definition();
            const IType_function *ct = as<IType_function>(callee->get_type());
            const IType *rt = ct->get_return_type();
            bool is_stateles = is_stateless_return_type(rt);
            auto callee_name = callee_def->get_symbol()->get_name();
            if (is_state_semantics(callee_def->get_semantics())) {
                add_to_code("state.");
                add_to_code(callee_name);
                for (int i = 0; i < c->get_argument_count(); ++i) {
                    const IArgument *arg = c->get_argument(i);
                    const IExpression *exp = arg->get_argument_expr();
                    add_to_code("_");
                    add_to_code(type_to_string_for_mangling(exp->get_type(), true));
                }
                add_to_code("(");


                for (int i = 0; i < c->get_argument_count(); ++i) {
                    const IArgument *arg = c->get_argument(i);
                    const IExpression *exp = arg->get_argument_expr();

                    dispatch_transpile_expression(exp, closure);

                    add_to_code(", ");
                }

                add_to_code(")");

                return;
            }
            if (is_math_semantics(callee_def->get_semantics())) {
                add_to_code("math.");
                add_to_code(callee_name);
                add_to_code("_");
                for (int i = 0; i < c->get_argument_count(); ++i) {
                    const IArgument *arg = c->get_argument(i);
                    const IExpression *exp = arg->get_argument_expr();
                    add_to_code("_");
                    add_to_code(type_to_string_for_mangling(exp->get_type(), true));
                }
                add_to_code("(\n");

                indent_level++;
                add_to_code("", true);

                for (int i = 0; i < c->get_argument_count(); ++i) {
                    const IArgument *arg = c->get_argument(i);
                    const IExpression *exp = arg->get_argument_expr();

                    dispatch_transpile_expression(exp, closure);

                    add_to_code(",\n");
                }
                indent_level--;
                add_to_code(")", true);

                return;
            }
            if (callee->get_name()->is_array()) {
                add_to_code("[");
                for (int i = 0; i < c->get_argument_count(); ++i) {
                    if (i > 0) {
                        add_to_code(",");
                    }
                    dispatch_transpile_expression(c->get_argument(i)->get_argument_expr(), closure);
                }
                add_to_code("]");
                return;
            }
            add_to_code(callee_name);
            add_to_code("_");
            for (int i = 0; i < c->get_argument_count(); ++i) {
                const IArgument *arg = c->get_argument(i);
                const IExpression *exp = arg->get_argument_expr();
                auto t = type_to_string_for_mangling(exp->get_type(), true);
                if (t == "string") {
                    continue;
                }
                add_to_code("_");
                add_to_code(t);
            }

            if (!is_constructor(callee_def->get_semantics()) && !is_stateles) {
                add_to_code("_State");
            }

            add_to_code("_mdl_math");
            add_to_code("(\n");
            indent_level++;

            for (int i = 0; i < c->get_argument_count(); ++i) {
                const IArgument *arg = c->get_argument(i);
                const IExpression *exp = arg->get_argument_expr();
                auto t = type_to_string_for_mangling(exp->get_type(), true);
                if (t == "string") {
                    continue;
                }

                add_to_code("", true);
                if (is_stateles) {
                    add_to_code("|state:State|{");
                    dispatch_transpile_expression(exp, true);
                    add_to_code("}");
                } else {
                    dispatch_transpile_expression(exp, closure);
                }

                add_to_code(",\n");
            }
            if (!is_constructor(callee_def->get_semantics()) && !is_stateles) {
                add_to_code("state,\n", true);
            }


            add_to_code("math\n", true);
            indent_level--;
            add_to_code(")", true);

        }


        bool AnyDSL_Transpiler::is_assign_operator(const IExpression_binary::Operator op) {
            switch (op) {
                case IExpression_binary::OK_ASSIGN:
                case IExpression_binary::OK_MULTIPLY_ASSIGN:
                case IExpression_binary::OK_DIVIDE_ASSIGN:
                case IExpression_binary::OK_MODULO_ASSIGN:
                case IExpression_binary::OK_PLUS_ASSIGN:
                case IExpression_binary::OK_MINUS_ASSIGN:
                case IExpression_binary::OK_SHIFT_LEFT_ASSIGN:
                case IExpression_binary::OK_SHIFT_RIGHT_ASSIGN:
                case IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT_ASSIGN:
                case IExpression_binary::OK_BITWISE_AND_ASSIGN:
                case IExpression_binary::OK_BITWISE_XOR_ASSIGN:
                case IExpression_binary::OK_BITWISE_OR_ASSIGN:
                    return true;
                default:
                    return false;
            }
        }

        const std::string AnyDSL_Transpiler::binary_operator_to_string(const IExpression_binary::Operator op) {
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

        const std::string AnyDSL_Transpiler::unary_operator_to_string(const IExpression_unary::Operator op) {
            switch (op) {
                case IExpression_unary::OK_BITWISE_COMPLEMENT:
                    return "bit_comp";
                case IExpression_unary::OK_LOGICAL_NOT:
                    return "not";
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

        bool AnyDSL_Transpiler::is_assign_operator(const IExpression_unary::Operator op) {
            switch (op) {
                case IExpression_unary::OK_PRE_INCREMENT:
                case IExpression_unary::OK_PRE_DECREMENT:
                case IExpression_unary::OK_POST_INCREMENT:
                case IExpression_unary::OK_POST_DECREMENT:
                    return true;
                default:
                    return false;
            }
        }


        bool AnyDSL_Transpiler::is_stateless_return_type(const IType *type) {
            std::string t = type_to_string_for_mangling(type, false);
            return stateless_return_types.find(t) != stateless_return_types.end();
        }

        bool AnyDSL_Transpiler::is_shorthand_assign_operator(IExpression_binary::Operator op) {
            switch (op) {
                case IExpression_binary::OK_MULTIPLY_ASSIGN:
                case IExpression_binary::OK_DIVIDE_ASSIGN:
                case IExpression_binary::OK_MODULO_ASSIGN:
                case IExpression_binary::OK_PLUS_ASSIGN:
                case IExpression_binary::OK_MINUS_ASSIGN:
                case IExpression_binary::OK_SHIFT_LEFT_ASSIGN:
                case IExpression_binary::OK_SHIFT_RIGHT_ASSIGN:
                case IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT_ASSIGN:
                case IExpression_binary::OK_BITWISE_AND_ASSIGN:
                case IExpression_binary::OK_BITWISE_XOR_ASSIGN:
                case IExpression_binary::OK_BITWISE_OR_ASSIGN:
                    return true;
                default:
                    return false;
            }
        }

        IExpression_binary::Operator AnyDSL_Transpiler::get_shorthand_operator(IExpression_binary::Operator op) {
            switch (op) {
                case IExpression_binary::OK_MULTIPLY_ASSIGN:
                    return IExpression_binary::OK_MULTIPLY;
                case IExpression_binary::OK_DIVIDE_ASSIGN:
                    return IExpression_binary::OK_DIVIDE;
                case IExpression_binary::OK_MODULO_ASSIGN:
                    return IExpression_binary::OK_MODULO;
                case IExpression_binary::OK_PLUS_ASSIGN:
                    return IExpression_binary::OK_PLUS;
                case IExpression_binary::OK_MINUS_ASSIGN:
                    return IExpression_binary::OK_MINUS;
                case IExpression_binary::OK_SHIFT_LEFT_ASSIGN:
                    return IExpression_binary::OK_SHIFT_LEFT;
                case IExpression_binary::OK_SHIFT_RIGHT_ASSIGN:
                    return IExpression_binary::OK_SHIFT_RIGHT;
                case IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT_ASSIGN:
                    return IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT;
                case IExpression_binary::OK_BITWISE_AND_ASSIGN:
                    return IExpression_binary::OK_BITWISE_AND;
                case IExpression_binary::OK_BITWISE_XOR_ASSIGN:
                    return IExpression_binary::OK_BITWISE_XOR;
                case IExpression_binary::OK_BITWISE_OR_ASSIGN:
                    return IExpression_binary::OK_BITWISE_OR;
                default:
                    return IExpression_binary::OK_ASSIGN;
            }
        }


    }  // namespace mdl

}  // namespace mi
