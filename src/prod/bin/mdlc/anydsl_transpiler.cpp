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
            out += "static ";
            out += definition->get_symbol()->get_name();
            out += " : ";
            out += type_to_string(definition->get_type());
            out += " = ";
            out += value_to_string(definition->get_constant_value());
            out += ";\n";


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
                    out += "enum ";
                    break;
                case IType::TK_STRUCT:
                    out += "struct ";
                    break;
                case IType::TK_TEXTURE:
                    out += "texture ";
                    break;
                case IType::TK_BSDF_MEASUREMENT:
                    out += "bsdf_measurement ";
                    break;
                case IType::TK_BSDF:
                    out += "bsdf ";
                    break;
                case IType::TK_VDF:
                    out += "vdf ";
                    break;
                case IType::TK_EDF:
                    out += "edf ";
                    break;
                case IType::TK_LIGHT_PROFILE:
                    out += "light_profile ";
                    break;
                case IType::TK_MATRIX:
                    out += "matrix ";
                    break;
                case IType::TK_COLOR:
                    out += "color ";
                    break;
                case IType::TK_STRING:
                    out += "string ";
                    break;
                case IType::TK_VECTOR:
                    out += "vector ";
                    break;
                case IType::TK_DOUBLE:
                    out += "double ";
                    break;
                case IType::TK_BOOL:
                    out += "bool ";
                    break;
                case IType::TK_FLOAT:
                    out += "float ";
                    break;
                case IType::TK_INT:
                    out += "int ";
                    break;
                default:
                    NOT_IMPLEMENTED;
            }
            out += definition->get_symbol()->get_name();
            if (definition->get_declaration() != nullptr) {
                dispatch_transpile_declaration(definition->get_declaration());
            } else {
                out += ";\n";
            }

        }

        void AnyDSL_Transpiler::transpile_function(const IDefinition *definition) {
            auto const *fun_type = as<IType_function>(definition->get_type());
            int parameter_count = fun_type->get_parameter_count();
            std::vector<int> possible_overloads = {parameter_count};
            std::vector<std::string> argument_types = std::vector<std::string>();
            std::vector<std::string> argument_names = std::vector<std::string>();
            std::vector<bool> has_default = std::vector<bool>();

            auto fname = std::string(definition->get_symbol()->get_name());

            for (int k = 0; k < parameter_count; ++k) {
                IType const *parameter_type = nullptr;
                ISymbol const *parameter_symbol = nullptr;

                fun_type->get_parameter(k, parameter_type, parameter_symbol);

                argument_types.push_back(type_to_string(parameter_type));
                argument_names.emplace_back(parameter_symbol->get_name());
                has_default.push_back(definition->get_default_param_initializer(k) != nullptr);
            }

            int counter = has_default.size() - 1;
            while (counter >= 0) {
                if (!has_default[counter]) {
                    break;
                }
                possible_overloads.push_back(counter);
                counter--;
            }

            for (int overload : possible_overloads) {
                out += "fn ";
                out += fname;
                out += "_";
                for (int i = 0; i < overload; i++) {
                    out += "_";
                    out += argument_types[i];
                }
                out += "(";
                for (int i = 0; i < overload; i++) {
                    out += argument_names[i];
                    out += " : ";
                    out += argument_types[i];
                    out += ",";
                }
                out += ") -> ";
                out += type_to_string(fun_type->get_return_type());
                if (definition->get_declaration() != nullptr) {
                    out += "{\n";
                    for (int j = overload; j < parameter_count; j++) {
                        out += "let ";
                        out += argument_names[j];
                        out += " = ";
                        dispatch_transpile_expression(definition->get_default_param_initializer(overload));
                        out += ";\n";
                    }
                    dispatch_transpile_declaration(definition->get_declaration());
                    out += "}\n";
                } else {
                    out += ";\n";
                }


            }


        }

        void AnyDSL_Transpiler::transpile_constructor(const IDefinition *definition) {
            transpile_function(definition);
        }

        void AnyDSL_Transpiler::transpile_operator(const IDefinition *definition) {
            auto const *fun_type = as<IType_function>(definition->get_type());
            int parameter_count = fun_type->get_parameter_count();
            std::vector<int> possible_overloads = {parameter_count};
            std::vector<std::string> argument_types = std::vector<std::string>();
            std::vector<std::string> argument_names = std::vector<std::string>();
            std::vector<bool> has_default = std::vector<bool>();

            auto fname = "op_" + std::string(definition->get_symbol()->get_name());

            for (int k = 0; k < parameter_count; ++k) {
                IType const *parameter_type = nullptr;
                ISymbol const *parameter_symbol = nullptr;

                fun_type->get_parameter(k, parameter_type, parameter_symbol);

                argument_types.push_back(type_to_string(parameter_type));
                argument_names.emplace_back(parameter_symbol->get_name());
                has_default.push_back(definition->get_default_param_initializer(k) != nullptr);
            }

            int counter = has_default.size() - 1;
            while (counter >= 0) {
                if (!has_default[counter]) {
                    break;
                }
                possible_overloads.push_back(counter);
                counter--;
            }

            for (int overload : possible_overloads) {
                out += "fn ";
                out += fname;
                out += "_";
                for (int i = 0; i < overload; i++) {
                    out += "_";
                    out += argument_types[i];
                }
                out += "(";
                for (int i = 0; i < overload; i++) {
                    out += argument_names[i];
                    out += " : ";
                    out += argument_types[i];
                    out += ",";
                }
                out += ") -> ";
                out += type_to_string(fun_type->get_return_type());
                if (definition->get_declaration() != nullptr) {
                    out += "{\n";
                    for (int j = overload; j < parameter_count; j++) {
                        out += "let ";
                        out += argument_names[j];
                        out += " = ";
                        dispatch_transpile_expression(definition->get_default_param_initializer(overload));
                        out += ";\n";
                    }
                    dispatch_transpile_declaration(definition->get_declaration());
                    out += "}\n";
                } else {
                    out += ";\n";
                }
            }
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
            out += "let mut ";
            out += definition->get_symbol()->get_name();
            out += " : ";
            out += type_to_string(definition->get_type());
            if (definition->get_declaration() != nullptr) {
                out += " = ";
                dispatch_transpile_declaration(definition->get_declaration());
            }
            out += ";\n";
        }

        const std::string AnyDSL_Transpiler::type_to_string(const IType *type) {
            switch (type->get_kind()) {
                case IType::TK_ALIAS: {
                    const IType_alias *t = as<IType_alias>(type);
                    return type_to_string(t->get_aliased_type());
                }
                case IType::TK_BOOL:
                    return "bool";
                case IType::TK_INT:
                    return "int";
                case IType::TK_ENUM: {
                    const auto *t = as<IType_enum>(type);
                    return t->get_symbol()->get_name();
                }
                case IType::TK_FLOAT:
                    return "float";
                case IType::TK_DOUBLE:
                    return "double";
                case IType::TK_STRING:
                    return "string";
                case IType::TK_LIGHT_PROFILE:
                    return "light_profile";
                case IType::TK_BSDF:
                    return "bsdf";
                case IType::TK_EDF:
                    return "edf";
                case IType::TK_VDF:
                    return "vdf";
                case IType::TK_VECTOR: {
                    auto t = as<IType_vector>(type);
                    return type_to_string(t->get_element_type()) + std::to_string(t->get_size());
                }
                case IType::TK_MATRIX: {
                    const IType_matrix *t = as<IType_matrix>(type);
                    return type_to_string(t->get_element_type()) + "x" + std::to_string(t->get_columns());
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
                    return str;
                }
                case IType::TK_COLOR:
                    return "color";
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

                    return str;
                }
                case IType::TK_STRUCT: {
                    const auto *t = as<IType_struct>(type);
                    return t->get_symbol()->get_name();
                }
                case IType::TK_TEXTURE: {
                    const IType_texture *tex = as<IType_texture>(type);
                    switch (tex->get_shape()) {

                        case IType_texture::TS_2D:
                            return "texture_2d";

                        case IType_texture::TS_3D:
                            return "texture_3d";

                        case IType_texture::TS_CUBE:
                            return "texture_cube";

                        case IType_texture::TS_PTEX:
                            return "texture_ptex";

                    }
                }
                case IType::TK_BSDF_MEASUREMENT:
                    return "bsdf_measurement";
                case IType::TK_INCOMPLETE:
                    return "";
                case IType::TK_ERROR:
                    return "";
            }
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
                out += "{}\n";
            }
        }

        void AnyDSL_Transpiler::transpile_import(const IDeclaration *decl) {
            //NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_type_alias(const IDeclaration *decl) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_struct(const IDeclaration *decl) {
            const IDeclaration_type_struct *s = as<IDeclaration_type_struct>(decl);
            out += " {\n";
            for (int i = 0; i < s->get_field_count(); i++) {
                out += s->get_field_name(i)->get_symbol()->get_name();
                out += ": ";
                out += type_to_string(s->get_field_type_name(i)->get_type());
                out += ",\n";
            }
            out += "}\n\n";
            out += "fn ";
            out += s->get_name()->get_symbol()->get_name();
            out += "_() -> ";
            out += s->get_name()->get_symbol()->get_name();
            out += " {\n";
            out += s->get_name()->get_symbol()->get_name();
            out += "{";
            for (int i = 0; i < s->get_field_count(); i++) {
                out += s->get_field_name(i)->get_symbol()->get_name();
                out += ": ";
                auto e = s->get_field_init(i);
                if (e != nullptr) {
                    dispatch_transpile_expression(s->get_field_init(i));
                } else {
                    out += type_to_string(s->get_field_type_name(i)->get_type());
                    out += "_()";
                }
                out += ",\n";
            }
            out += "}\n}\n";

            out += "fn ";
            out += s->get_name()->get_symbol()->get_name();
            out += "_";
            out += s->get_name()->get_symbol()->get_name();
            out += "(copy: ";
            out += s->get_name()->get_symbol()->get_name();
            out += ") -> ";
            out += s->get_name()->get_symbol()->get_name();
            out += " {\n";
            out += s->get_name()->get_symbol()->get_name();
            out += "{";
            for (int i = 0; i < s->get_field_count(); i++) {
                out += s->get_field_name(i)->get_symbol()->get_name();
                out += ": copy.";
                out += s->get_field_name(i)->get_symbol()->get_name();
                out += ",\n";
            }
            out += "}\n}\n";


        }

        void AnyDSL_Transpiler::transpile_enum_declaration(const IDeclaration *decl) {
            const IDeclaration_type_enum *e = as<IDeclaration_type_enum>(decl);
            out += "{\n";
            for (int i = 0; i < e->get_value_count(); i++) {
                out += e->get_value_name(i)->get_symbol()->get_name();
                out += ",\n";
            }
            out += "}\n";
        }

        void AnyDSL_Transpiler::transpile_variable_declaration(
                const IDeclaration *decl) {

            const IDeclaration_variable *v = as<IDeclaration_variable>(decl);
            for (int i = 0; i < v->get_variable_count(); i++) {
                out += "let mut ";
                out += v->get_variable_name(i)->get_symbol()->get_name();
                out += ": ";
                out += type_to_string(v->get_type_name()->get_type());
                if (v->get_variable_init(i) != nullptr) {
                    out += " = ";
                    dispatch_transpile_expression(v->get_variable_init(i));
                }
                out += ";\n";
            }
        }

        void AnyDSL_Transpiler::transpile_constant_declaration(const IDeclaration *decl) {
            const IDeclaration_constant *c = as<IDeclaration_constant>(decl);
            for (int i = 0; i < c->get_constant_count(); i++) {
                out += "static ";
                out += c->get_constant_name(i)->get_symbol()->get_name();
                out += ": ";
                out += type_to_string(c->get_type_name()->get_type());
                if (c->get_constant_exp(i) != nullptr) {
                    out += " = ";
                    dispatch_transpile_expression(c->get_constant_exp(i));
                }
                out += ";\n";
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
            out += "{\n";

            for (int i = 0; i < sc->get_statement_count(); i++) {

                dispatch_transpile_statement(sc->get_statement(i));
            }

            out += "}\n";
        }

        void AnyDSL_Transpiler::transpile_return_statement(const IStatement *stat) {
            auto r = as<IStatement_return>(stat);
            dispatch_transpile_expression(r->get_expression());
            out += "\n";
        }

        void AnyDSL_Transpiler::transpile_break_statement(const IStatement *stat) {
            out += "break;\n";
        }

        void AnyDSL_Transpiler::transpile_do_while_statement(const IStatement *stat) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_expression_statement(const IStatement *stat) {
            const auto *e = as<IStatement_expression>(stat);
            dispatch_transpile_expression(e->get_expression());
        }

        void AnyDSL_Transpiler::transpile_switch_statement(const IStatement *stat) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_continue_statement(const IStatement *stat) {
            out += "continue;\n";
        }

        void AnyDSL_Transpiler::transpile_for_statement(const IStatement *stat) {
            const IStatement_for *f = as<IStatement_for>(stat);
            out += "{\n";
            dispatch_transpile_statement(f->get_init());
            out += "{\n";
            dispatch_transpile_statement(f->get_body());
            out += "}\n";
            dispatch_transpile_expression(f->get_update());
            out += "}\n";
        }

        void AnyDSL_Transpiler::transpile_while_statement(const IStatement *stat) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_case_statement(const IStatement *stat) {
            NOT_IMPLEMENTED;
        }

        void AnyDSL_Transpiler::transpile_if_statement(const IStatement *stat) {
            auto f = as<IStatement_if>(stat);
            out += "if (";
            dispatch_transpile_expression(f->get_condition());
            out += ") {\n";
            dispatch_transpile_statement(f->get_then_statement());
            out += "}";
            auto el = f->get_else_statement();
            if (el != nullptr) {
                out += " else {\n";
                dispatch_transpile_statement(f->get_else_statement());
                out += "}";
            }
            out += "\n";
        }

        void AnyDSL_Transpiler::transpile_declaration_statement(
                const IStatement *stat) {
            dispatch_transpile_declaration(
                    as<IStatement_declaration>(stat)->get_declaration());
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
            out += s;
        }

        void AnyDSL_Transpiler::transpile_expression_let(
                const IExpression *pExpression) {
            const auto *l = as<IExpression_let>(pExpression);

            for (int i = 0; i < l->get_declaration_count(); i++) {
                dispatch_transpile_declaration(l->get_declaration(i));
            }
            out += "{\n";
            dispatch_transpile_expression(l->get_expression());
            out += "}\n";
        }

        void AnyDSL_Transpiler::transpile_expression_conditional(
                const IExpression *pExpression) {
            auto conditional = as<IExpression_conditional>(pExpression);
            out += "if (";
            dispatch_transpile_expression(conditional->get_condition());
            out += ") {";
            dispatch_transpile_expression(conditional->get_true());
            out += "} else {";
            dispatch_transpile_expression(conditional->get_false());
            out += "}";
        }

        void AnyDSL_Transpiler::transpile_expression_unary(
                const IExpression *pExpression) {
            auto un = as<IExpression_unary>(pExpression);

            out += unary_operator_to_string(un->get_operator());
            out += "__";
            out += type_to_string(un->get_argument()->get_type());
            out += "(";
            dispatch_transpile_expression(un->get_argument());
            out += ")";

        }

        void AnyDSL_Transpiler::transpile_expression_reference(
                const IExpression *pExpression) {
            const IExpression_reference *ref = as<IExpression_reference>(pExpression);
            out += ref->get_definition()->get_symbol()->get_name();
        }

        void AnyDSL_Transpiler::transpile_expression_binary(
                const IExpression *pExpression) {
            auto bin = as<IExpression_binary>(pExpression);
            switch(bin->get_operator()){

                case IExpression_binary::OK_SELECT:
                    dispatch_transpile_expression(bin->get_left_argument());
                    out += ".";
                    dispatch_transpile_expression(bin->get_right_argument());
                    break;

                default:
                    out += binary_operator_to_string(bin->get_operator());
                    out += "__";
                    out += type_to_string(bin->get_left_argument()->get_type());
                    out += "_";
                    out += type_to_string(bin->get_right_argument()->get_type());
                    out += "(";
                    dispatch_transpile_expression(bin->get_left_argument());
                    out += ", ";
                    dispatch_transpile_expression(bin->get_right_argument());
                    out += ")";




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
            out += calle_name;
            out += "_";
            for (int i = 0; i < c->get_argument_count(); ++i) {
                const IArgument *arg = c->get_argument(i);
                const IExpression *exp = arg->get_argument_expr();
                out += "_";
                out += type_to_string(exp->get_type());
            }
            out += "(";

            for (int i = 0; i < c->get_argument_count(); ++i) {
                const IArgument *arg = c->get_argument(i);
                const IExpression *exp = arg->get_argument_expr();
                dispatch_transpile_expression(exp);
                out += ", ";
            }
            out += ")";
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
    } // namespace mdl

} // namespace mi
