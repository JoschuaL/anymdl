//
// Created by Noisyedge on 2019-05-19.
//

#include "ast_dumper.h"

#include "pch.h"

#include <mi/base/handle.h>
#include <mi/mdl/mdl_code_generators.h>

#include <mdl/compiler/compilercore/compilercore_cc_conf.h>
#include <mdl/compiler/compilercore/compilercore_streams.h>
#include <mdl/compiler/compilercore/compilercore_mdl.h>
#include <mdl/compiler/compilercore/compilercore_visitor.h>
#include <mdl/compiler/compilercore/compilercore_file_resolution.h>
#include <mdl/codegenerators/generator_code/generator_code_hash.h>

#include <cstring>


namespace mi {
    namespace mdl {

        void AST_Dumper::dump_module_ast(const IModule *module) {
            printf("Dumping AST\n");
            const char *module_name = module->get_name();
            printf("digraph %s {\n", module_name);
            int node_counter = 0;

            /*for (int i = 0, n = module->get_exported_definition_count(); i < n; ++i) {
                IDefinition const *def = module->get_exported_definition(i);
               // collect_types(module, def, collector);
            }

            if (IDeclaration_module const *mod_decl = module->get_module_declararation()) {
                //gen_module_annotations(dag_builder, mod_decl);
            }*/

            // ... collect types and constants ... these are not really needed for the compilation itself
            for (int i = 0, n = module->get_exported_definition_count(); i < n; ++i) {
                IDefinition const *def = module->get_exported_definition(i);
                /*switch (def->get_kind()) {
                    case IDefinition::DK_CONSTANT:
                        //compile_constant(dag_builder, def);
                        break;
                    case IDefinition::DK_TYPE:
                        //compile_type(dag_builder, def);
                        break;
                    default:
                        break;
                }*/
                dispatch_dump_definition(def, &node_counter);
            }

            printf("}");

        }


        void AST_Dumper::dispatch_dump_definition(const IDefinition *def, int *node_counter) {
            switch (def->get_kind()) {

                case IDefinition::DK_ERROR:
                    break;
                case IDefinition::DK_CONSTANT:
                    dump_constant(def, node_counter);
                    break;
                case IDefinition::DK_ENUM_VALUE:
                    dump_enum_value(def, node_counter);
                    break;
                case IDefinition::DK_ANNOTATION:
                    dump_annotation(def, node_counter);
                    break;
                case IDefinition::DK_TYPE:
                    dump_type(def, node_counter);
                    break;
                case IDefinition::DK_FUNCTION:
                    dump_funcion(def, node_counter);
                    break;
                case IDefinition::DK_VARIABLE:
                    dump_variable(def, node_counter);
                    break;
                case IDefinition::DK_MEMBER:
                    dump_member(def, node_counter);
                    break;
                case IDefinition::DK_CONSTRUCTOR:
                    dump_constructor(def, node_counter);
                    break;
                case IDefinition::DK_PARAMETER:
                    dump_parameter(def, node_counter);
                    break;
                case IDefinition::DK_ARRAY_SIZE:
                    dump_array_size(def, node_counter);
                    break;
                case IDefinition::DK_OPERATOR:
                    dump_operator(def, node_counter);
                    break;
            }
        }

        void AST_Dumper::dump_constant(const IDefinition *definition, int *node_counter) {

        }

        void AST_Dumper::dump_enum_value(const IDefinition *definition, int *node_counter) {

        }

        void AST_Dumper::dump_annotation(const IDefinition *definition, int *node_counter) {

        }

        void AST_Dumper::dump_type(const IDefinition *definition, int *node_counter) {

        }

        void AST_Dumper::dump_funcion(const IDefinition *definition, int *node_counter) {
            IType_function const *fun_type = as<IType_function>(definition->get_type());
            int parameter_count = fun_type->get_parameter_count();

            for (int k = 0; k < parameter_count; ++k) {
                IType const *parameter_type;
                ISymbol const *parameter_symbol;

                fun_type->get_parameter(k, parameter_type, parameter_symbol);


                /*// import the parameter type into our type factory
                parameter_type = m_type_factory.import(parameter_type);

                Parameter_info param(get_allocator(), parameter_type, parameter_symbol->get_name());

                mat.add_parameter(param);*/
            }


            auto fname = definition->get_symbol()->get_name();
            IType_function const *ftype = as<IType_function>(definition->get_type());
            int root = *node_counter;
            printf("%i [label=\"Function\\n%s\"];", *node_counter, fname);
            *node_counter += 1;
            printf("%i -> %i;", root, *node_counter);
            printf("%i [label=\"return\\n%s\"];", *node_counter, type_to_string(ftype->get_return_type()));
            *node_counter += 1;

            for (int k = 0; k < parameter_count; ++k) {
                IType const *parameter_type;
                ISymbol const *parameter_symbol;

                fun_type->get_parameter(k, parameter_type, parameter_symbol);
                printf("%i -> %i;", root, *node_counter);
                printf("%i [label=\"%s\\n%s\"];", *node_counter, type_to_string(parameter_type),
                       parameter_symbol->get_name());
                *node_counter += 1;


            }

            printf("%i -> %i;", root, *node_counter);
            dispatch_dump_declaration(definition->get_declaration(), node_counter);


        }

        void AST_Dumper::dump_constructor(const IDefinition *definition, int *node_counter) {

        }

        void AST_Dumper::dump_operator(const IDefinition *definition, int *node_counter) {

        }

        void AST_Dumper::dump_member(const IDefinition *definition, int *node_counter) {

        }

        void AST_Dumper::dump_parameter(const IDefinition *definition, int *node_counter) {

        }

        void AST_Dumper::dump_array_size(const IDefinition *definition, int *node_counter) {

        }

        void AST_Dumper::dump_variable(const IDefinition *definition, int *node_counter) {

        }

        const char *AST_Dumper::type_to_string(const IType *type) {
            switch (type->get_kind()) {

                case IType::TK_ALIAS: {
                    const IType_alias *t = as<IType_alias>(type);
                    return t->get_symbol()->get_name();
                }
                case IType::TK_BOOL:
                    return "bool";
                case IType::TK_INT:
                    return "int";
                case IType::TK_ENUM: {
                    const IType_enum *t = as<IType_enum>(type);
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
                    const IType_vector *t = as<IType_vector>(type);
                    std::string s1("[");
                    std::string s2("]");
                    std::string s3(type_to_string(t->get_element_type()));
                    std::string s4 = std::to_string(t->get_size());
                    std::string s5("*");
                    auto str = new std::string();
                    *str = s1 + s3 + s5 + s4 + s2;
                    return str->c_str();
                }
                case IType::TK_MATRIX: {
                    const IType_matrix *t = as<IType_matrix>(type);
                    std::string s1("[");
                    std::string s2("]");
                    std::string s3(type_to_string(t->get_element_type()));
                    std::string s4 = std::to_string(t->get_columns());
                    std::string s5("*");
                    auto str = new std::string();
                    *str = s1 + s3 + s5 + s4 + s2;
                    return str->c_str();
                }


                case IType::TK_ARRAY: {
                    const IType_array *t = as<IType_array>(type);
                    std::string s1("[");
                    std::string s2("]");
                    std::string s3(type_to_string(t->get_element_type()));
                    std::string s4 = std::to_string(t->get_size());
                    std::string s5("*");
                    auto str = new std::string();
                    *str = s1 + s3 + s5 + s4 + s2;
                    return str->c_str();
                }
                case IType::TK_COLOR:
                    return "color";
                case IType::TK_FUNCTION: {
                    const IType_function *t = as<IType_function>(type);
                    std::string s1("(");
                    std::string s2(") -> (");
                    std::string s3(")");
                    std::string s4(",");
                    const IType *itype;
                    const ISymbol *iSymbol;
                    auto *str = new std::string();
                    *str += "(";
                    for (int i = 0; i < t->get_parameter_count(); i++) {
                        if (i != 0) {
                            *str += ",";
                        }
                        t->get_parameter(i, itype, iSymbol);
                        *str += iSymbol->get_name();
                    }
                    *str += ") -> (";
                    *str += type_to_string(t->get_return_type());
                    *str += ")";

                    return str->c_str();
                }
                case IType::TK_STRUCT: {
                    const IType_struct *t = as<IType_struct>(type);
                    return t->get_symbol()->get_name();
                    break;
                }
                case IType::TK_TEXTURE:
                    return "texture";
                case IType::TK_BSDF_MEASUREMENT:
                    return "bsdf_measurement";
                case IType::TK_INCOMPLETE:
                    return "";
                case IType::TK_ERROR:
                    return "";
            }
        }

        void AST_Dumper::dispatch_dump_declaration(const IDeclaration *decl, int *node_counter) {
            switch (decl->get_kind()) {

                case IDeclaration::DK_INVALID:
                    break;
                case IDeclaration::DK_IMPORT:
                    dump_import(decl, node_counter);
                    break;
                case IDeclaration::DK_ANNOTATION:
                    dump_annotation_declaration(decl, node_counter);
                    break;
                case IDeclaration::DK_CONSTANT:
                    dump_constant_declaration(decl, node_counter);
                    break;
                case IDeclaration::DK_TYPE_ALIAS:
                    dump_type_alias(decl, node_counter);
                    break;
                case IDeclaration::DK_TYPE_STRUCT:
                    dump_struct(decl, node_counter);
                    break;
                case IDeclaration::DK_TYPE_ENUM:
                    dump_enum_declaration(decl, node_counter);
                    break;
                case IDeclaration::DK_VARIABLE:
                    dump_variable_declaration(decl, node_counter);
                    break;
                case IDeclaration::DK_FUNCTION:
                    dump_funcion_declaration(decl, node_counter);
                    break;
                case IDeclaration::DK_MODULE:
                    dump_module_declaration(decl, node_counter);
                    break;
            }

        }

        void AST_Dumper::dump_module_declaration(const IDeclaration *decl, int *node_counter) {
            const IDeclaration_module *d = as<IDeclaration_module>(decl);


        }

        void AST_Dumper::dump_funcion_declaration(const IDeclaration *decl, int *node_counter) {
            const IDeclaration_function *d = as<IDeclaration_function>(decl);
            const IStatement *s = d->get_body();
            dispatch_dump_statement(s, node_counter);

        }

        void AST_Dumper::dump_import(const IDeclaration *decl, int *node_counter) {

        }

        void AST_Dumper::dump_type_alias(const IDeclaration *decl, int *node_counter) {

        }

        void AST_Dumper::dump_struct(const IDeclaration *decl, int *node_counter) {

        }

        void AST_Dumper::dump_enum_declaration(const IDeclaration *decl, int *node_counter) {

        }

        void AST_Dumper::dump_variable_declaration(const IDeclaration *decl, int *node_counter) {

        }

        void AST_Dumper::dump_constant_declaration(const IDeclaration *decl, int *node_counter) {

        }

        void AST_Dumper::dump_annotation_declaration(const IDeclaration *decl, int *node_counter) {

        }

        void AST_Dumper::dispatch_dump_statement(const IStatement *stat, int *node_counter) {
            switch (stat->get_kind()) {

                case IStatement::SK_INVALID:
                    break;
                case IStatement::SK_COMPOUND:
                    dump_compound_statement(stat, node_counter);
                    break;
                case IStatement::SK_DECLARATION:
                    dump_declaration_statement(stat, node_counter);
                    break;
                case IStatement::SK_EXPRESSION:
                    dump_expression_statement(stat, node_counter);
                    break;
                case IStatement::SK_IF:
                    dump_if_statement(stat, node_counter);
                    break;
                case IStatement::SK_CASE:
                    dump_case_statement(stat, node_counter);
                    break;
                case IStatement::SK_SWITCH:
                    dump_switch_statement(stat, node_counter);
                    break;
                case IStatement::SK_WHILE:
                    dump_while_statement(stat, node_counter);
                    break;
                case IStatement::SK_DO_WHILE:
                    dump_do_while_statement(stat, node_counter);
                    break;
                case IStatement::SK_FOR:
                    dump_for_statement(stat, node_counter);
                    break;
                case IStatement::SK_BREAK:
                    dump_break_statement(stat, node_counter);
                    break;
                case IStatement::SK_CONTINUE:
                    dump_continue_statement(stat, node_counter);
                    break;
                case IStatement::SK_RETURN:
                    dump_return_statement(stat, node_counter);
                    break;
            }

        }

        void AST_Dumper::dump_compound_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_return_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_break_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_do_while_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_expression_statement(const IStatement *stat, int *node_counter) {
            const IStatement_expression *e = as<IStatement_expression>(stat);
            dispatch_dump_expression(e->get_expression(), node_counter);


        }

        void AST_Dumper::dump_switch_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_continue_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_for_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_while_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_case_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_if_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dump_declaration_statement(const IStatement *stat, int *node_counter) {

        }

        void AST_Dumper::dispatch_dump_expression(const IExpression *exp, int *node_counter) {
            switch (exp->get_kind()) {

                case IExpression::EK_INVALID:
                    break;
                case IExpression::EK_LITERAL:
                    dump_expression_literal(exp, node_counter);
                    break;
                case IExpression::EK_REFERENCE:
                    dump_expression_reference(exp,  node_counter);
                    break;
                case IExpression::EK_UNARY:
                    dump_expression_unary(exp, node_counter);
                    break;
                case IExpression::EK_BINARY:
                    dump_expression_binary(exp, node_counter);
                    break;
                case IExpression::EK_CONDITIONAL:
                    dump_expression_conditional(exp, node_counter);
                    break;
                case IExpression::EK_CALL:
                    dump_expression_call(exp, node_counter);
                    break;
                case IExpression::EK_LET:
                    dump_expression_let(exp, node_counter);
                    break;
            }

        }

        void AST_Dumper::dump_expression_literal(const IExpression *pExpression, int *pInt) {

        }

        void AST_Dumper::dump_expression_let(const IExpression *pExpression, int *pInt) {

        }

        void AST_Dumper::dump_expression_conditional(const IExpression *pExpression, int *pInt) {

        }

        void AST_Dumper::dump_expression_unary(const IExpression *pExpression, int *pInt) {

        }

        void AST_Dumper::dump_expression_reference(const IExpression *pExpression, int *pInt) {

        }

        void AST_Dumper::dump_expression_binary(const IExpression *pExpression, int *pInt) {

        }

        void AST_Dumper::dump_expression_call(const IExpression *pExpression, int *pInt) {

        }
    }
}
