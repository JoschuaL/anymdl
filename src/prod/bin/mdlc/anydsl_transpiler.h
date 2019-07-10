//
// Created by Noisyedge on 2019-05-19.
//

#ifndef MDL_ANYDSL_TRANSPILER_H
#define MDL_ANYDSL_TRANSPILER_H

#include <mdl/compiler/compilercore/compilercore_allocator.h>
#include <mi/mdl/mdl_modules.h>
#include <iostream>

namespace mi {
    namespace mdl {
        class AnyDSL_Transpiler {
        public:
            void transpile_module(const IModule *module);

            std::string get_code() { return this->out; }

        private:
            std::string out = "";

            int indent_level = 0;

            std::string indent = "    ";

            void add_to_code(const std::string &str, bool indent = false);

            std::string indent_code(const std::string &str);

            std::unordered_set<std::string> imports = {"::math", "::state", "::df", "::limits", "::tex", "::debug", "::anno"};

            const std::unordered_set<std::string> stateless_return_types = {"material", "material_surface", "material_volume", "material_geometry", "bsdf", "material_emission", "edf", "vdf"};

            bool is_assign_operator(IExpression_binary::Operator op);

            bool is_assign_operator(IExpression_unary::Operator op);

            bool is_stateless_return_type(const IType *type);

            const std::string unary_operator_to_string(IExpression_unary::Operator op);

            const std::string binary_operator_to_string(IExpression_binary::Operator op);

            const std::string value_to_string(const IValue *l);

            bool is_prefix_operator(IExpression_unary::Operator op);

            void dispatch_transpile_declaration(const IDeclaration *decl);

            void dispatch_transpile_definition(const IDefinition *def);

            void transpile_constant(const IDefinition *definition);

            void transpile_enum_value(const IDefinition *definition);

            void transpile_annotation(const IDefinition *definition);

            void transpile_type(const IDefinition *definition);

            void transpile_function(const IDefinition *definition);

            void transpile_constructor(const IDefinition *definition);

            void transpile_operator(const IDefinition *definition);

            void transpile_member(const IDefinition *definition);

            void transpile_parameter(const IDefinition *definition);

            void transpile_array_size(const IDefinition *definition);

            void transpile_variable(const IDefinition *definition);

            const std::string type_to_string_closure(const IType *type);

            const std::string type_to_string_for_mangling(const IType *type, bool no_special_characters);

            void transpile_module_declaration(const IDeclaration *decl);

            void transpile_function_declaration(const IDeclaration *pDeclaration);

            void transpile_import(const IDeclaration *pDeclaration);

            void transpile_type_alias(const IDeclaration *pDeclaration);

            void transpile_struct(const IDeclaration *pDeclaration);

            void transpile_enum_declaration(const IDeclaration *pDeclaration);

            void transpile_variable_declaration(const IDeclaration *pDeclaration);

            void transpile_constant_declaration(const IDeclaration *pDeclaration);

            void transpile_annotation_declaration(const IDeclaration *pDeclaration);

            void dispatch_transpile_statement(const IStatement *stat);

            void transpile_compound_statement(const IStatement *pStatement);

            void transpile_return_statement(const IStatement *pStatement);

            void transpile_break_statement(const IStatement *pStatement);

            void transpile_do_while_statement(const IStatement *pStatement);

            void transpile_expression_statement(const IStatement *pStatement);

            void transpile_switch_statement(const IStatement *pStatement);

            void transpile_continue_statement(const IStatement *pStatement);

            void transpile_for_statement(const IStatement *pStatement);

            void transpile_while_statement(const IStatement *pStatement);

            void transpile_case_statement(const IStatement *pStatement);

            void transpile_if_statement(const IStatement *pStatement);

            void transpile_declaration_statement(const IStatement *pStatement);

            void dispatch_transpile_expression(const IExpression *exp, bool closure);



            void transpile_expression_literal(const IExpression *pExpression, bool closure);

            void transpile_expression_let(const IExpression *pExpression, bool closure);

            void transpile_expression_conditional(const IExpression *pExpression, bool closure);

            void transpile_expression_unary(const IExpression *pExpression, bool closure);

            void transpile_expression_reference(const IExpression *pExpression, bool closure);



            void transpile_expression_binary(const IExpression *pExpression, bool closure);

            void transpile_expression_call(const IExpression *pExpression, bool closure);
        };
    }  // namespace mdl
}  // namespace mi

#endif  // MDL_ANYDSL_TRANSPILER_H
