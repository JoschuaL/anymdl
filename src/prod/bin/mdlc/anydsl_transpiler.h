//
// Created by Noisyedge on 2019-05-19.
//

#ifndef MDL_AST_DUMPER_H
#define MDL_AST_DUMPER_H

#include <mdl/compiler/compilercore/compilercore_allocator.h>
#include <mi/mdl/mdl_modules.h>

namespace mi {
namespace mdl {
class AST_Dumper {
public:
  void dump_module_ast(const IModule *module);

private:
  const char *unary_operator_to_string(const IExpression_unary::Operator op);
  
  const char *binary_operator_to_string(const IExpression_binary::Operator op);

  const char *value_to_string(const IValue *l);

  void dispatch_dump_declaration(const IDeclaration *decl, int *node_counter);

  void dispatch_dump_definition(const IDefinition *def, int *node_counter);

  void dump_constant(const IDefinition *definition, int *node_counter);

  void dump_enum_value(const IDefinition *definition, int *node_counter);

  void dump_annotation(const IDefinition *definition, int *node_counter);

  void dump_type(const IDefinition *definition, int *node_counter);

  void dump_function(const IDefinition *definition, int *node_counter);

  void dump_constructor(const IDefinition *definition, int *node_counter);

  void dump_operator(const IDefinition *definition, int *node_counter);

  void dump_member(const IDefinition *definition, int *node_counter);

  void dump_parameter(const IDefinition *definition, int *node_counter);

  void dump_array_size(const IDefinition *definition, int *node_counter);

  void dump_variable(const IDefinition *definition, int *node_counter);

  const char *type_to_string(const IType *type);

  void dump_module_declaration(const IDeclaration *decl, int *node_counter);

  void dump_function_declaration(const IDeclaration *pDeclaration, int *pInt);

  void dump_import(const IDeclaration *pDeclaration, int *pInt);

  void dump_type_alias(const IDeclaration *pDeclaration, int *pInt);

  void dump_struct(const IDeclaration *pDeclaration, int *pInt);

  void dump_enum_declaration(const IDeclaration *pDeclaration, int *pInt);

  void dump_variable_declaration(const IDeclaration *pDeclaration, int *pInt);

  void dump_constant_declaration(const IDeclaration *pDeclaration, int *pInt);

  void dump_annotation_declaration(const IDeclaration *pDeclaration, int *pInt);

  void dispatch_dump_statement(const IStatement *stat, int *node_counter);

  void dump_compound_statement(const IStatement *pStatement, int *pInt);

  void dump_return_statement(const IStatement *pStatement, int *pInt);

  void dump_break_statement(const IStatement *pStatement, int *pInt);

  void dump_do_while_statement(const IStatement *pStatement, int *pInt);

  void dump_expression_statement(const IStatement *pStatement, int *pInt);

  void dump_switch_statement(const IStatement *pStatement, int *pInt);

  void dump_continue_statement(const IStatement *pStatement, int *pInt);

  void dump_for_statement(const IStatement *pStatement, int *pInt);

  void dump_while_statement(const IStatement *pStatement, int *pInt);

  void dump_case_statement(const IStatement *pStatement, int *pInt);

  void dump_if_statement(const IStatement *pStatement, int *pInt);

  void dump_declaration_statement(const IStatement *pStatement, int *pInt);

  void dispatch_dump_expression(const IExpression *exp, int *node_counter);

  void dump_expression_literal(const IExpression *pExpression, int *pInt);

  void dump_expression_let(const IExpression *pExpression, int *pInt);

  void dump_expression_conditional(const IExpression *pExpression, int *pInt);

  void dump_expression_unary(const IExpression *pExpression, int *pInt);

  void dump_expression_reference(const IExpression *pExpression, int *pInt);

  void dump_expression_binary(const IExpression *pExpression, int *pInt);

  void dump_expression_call(const IExpression *pExpression, int *pInt);
};
} // namespace mdl
} // namespace mi

#endif // MDL_AST_DUMPER_H
