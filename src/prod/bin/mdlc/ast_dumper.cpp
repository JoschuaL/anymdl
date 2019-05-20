//
// Created by Noisyedge on 2019-05-19.
//

#include "ast_dumper.h"

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

void AST_Dumper::dump_module_ast(const IModule *module) {
  const char *module_name = module->get_name();
  printf("digraph AST {", module_name);
  int node_counter = 0;

  /*for (int i = 0, n = module->get_exported_definition_count(); i < n; ++i) {
        IDefinition const *def = module->get_exported_definition(i);
       // collect_types(module, def, collector);
    }

    if (IDeclaration_module const *mod_decl =
module->get_module_declararation()) {
        //gen_module_annotations(dag_builder, mod_decl);
    }*/

  // ... collect types and constants ... these are not really needed for the
  // compilation itself
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

void AST_Dumper::dispatch_dump_definition(const IDefinition *def,
                                          int *node_counter) {
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

void AST_Dumper::dump_constant(const IDefinition *definition,
                               int *node_counter) {
  // const IValue* v = definition->get_constant_value();
  printf("%i [label=\"%s\"];\n", *node_counter,
         definition->get_symbol()->get_name());
  *node_counter += 1;
}

void AST_Dumper::dump_enum_value(const IDefinition *definition,
                                 int *node_counter) {
  printf("%i [label=\"%s\"];\n", *node_counter,
         definition->get_symbol()->get_name());
  *node_counter += 1;
}

void AST_Dumper::dump_annotation(const IDefinition *definition,
                                 int *node_counter) {
  printf("%i [label=\"%s\"];\n", *node_counter,
         definition->get_symbol()->get_name());
  *node_counter += 1;
}

void AST_Dumper::dump_type(const IDefinition *definition, int *node_counter) {
  printf("%i [label=\"%s\"];\n", *node_counter,
         definition->get_symbol()->get_name());
  *node_counter += 1;
}

void AST_Dumper::dump_funcion(const IDefinition *definition,
                              int *node_counter) {
  IType_function const *fun_type = as<IType_function>(definition->get_type());
  int parameter_count = fun_type->get_parameter_count();

  for (int k = 0; k < parameter_count; ++k) {
    IType const *parameter_type;
    ISymbol const *parameter_symbol;

    fun_type->get_parameter(k, parameter_type, parameter_symbol);

    /*// import the parameter type into our type factory
    parameter_type = m_type_factory.import(parameter_type);

    Parameter_info param(get_allocator(), parameter_type,
parameter_symbol->get_name());

    mat.add_parameter(param);*/
  }

  auto fname = definition->get_symbol()->get_name();
  IType_function const *ftype = as<IType_function>(definition->get_type());
  int root = *node_counter;
  printf("%i [label=\"Function\\n%s\"];\n", *node_counter, fname);
  *node_counter += 1;
  printf("%i -> %i;\n", root, *node_counter);
  printf("%i [label=\"return\\n%s\"];\n", *node_counter,
         type_to_string(ftype->get_return_type()));
  *node_counter += 1;

  for (int k = 0; k < parameter_count; ++k) {
    IType const *parameter_type;
    ISymbol const *parameter_symbol;

    fun_type->get_parameter(k, parameter_type, parameter_symbol);
    printf("%i -> %i;\n", root, *node_counter);
    printf("%i [label=\"%s\\n%s\"];\n", *node_counter,
           type_to_string(parameter_type), parameter_symbol->get_name());
    *node_counter += 1;
  }

  printf("%i -> %i;\n", root, *node_counter);
  dispatch_dump_declaration(definition->get_declaration(), node_counter);
}

void AST_Dumper::dump_constructor(const IDefinition *definition,
                                  int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_operator(const IDefinition *definition,
                               int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_member(const IDefinition *definition, int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_parameter(const IDefinition *definition,
                                int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_array_size(const IDefinition *definition,
                                 int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_variable(const IDefinition *definition,
                               int *node_counter) {
  NOT_IMPLEMENTED;
}

const char *AST_Dumper::type_to_string(const IType *type) {
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

void AST_Dumper::dispatch_dump_declaration(const IDeclaration *decl,
                                           int *node_counter) {
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
    dump_function_declaration(decl, node_counter);
    break;
  case IDeclaration::DK_MODULE:
    dump_module_declaration(decl, node_counter);
    break;
  }
}

void AST_Dumper::dump_module_declaration(const IDeclaration *decl,
                                         int *node_counter) {
  NOT_IMPLEMENTED;
  const IDeclaration_module *d = as<IDeclaration_module>(decl);
}

void AST_Dumper::dump_function_declaration(const IDeclaration *pDeclaration,
                                           int *pInt) {
  const IDeclaration_function *d = as<IDeclaration_function>(pDeclaration);
  printf("%i [label=\"%s\"];\n", *pInt, d->get_name()->get_symbol()->get_name());
  printf("%i -> %i;\n", *pInt, *pInt + 1);
  *pInt += 1;
  const IStatement *s = d->get_body();
  dispatch_dump_statement(s, pInt);
}

void AST_Dumper::dump_import(const IDeclaration *decl, int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_type_alias(const IDeclaration *decl, int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_struct(const IDeclaration *decl, int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_enum_declaration(const IDeclaration *decl,
                                       int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_variable_declaration(const IDeclaration *decl,
                                           int *node_counter) {
  const IDeclaration_variable *v = as<IDeclaration_variable>(decl);
  printf("%i [label=\"%s:\\n", *node_counter,
         type_to_string(v->get_type_name()->get_type()));
  for (int i = 0; i < v->get_variable_count(); i++) {
    printf("%s\\n", v->get_variable_name(i));
  }
  printf("\"];\n");
  int root = *node_counter;
  *node_counter += 1;
  for (int i = 0; i < v->get_variable_count(); i++) {
    auto vinit = v->get_variable_init(i);
    if (vinit != NULL) {
      printf("%i -> %i;\n", root, *node_counter);
      dispatch_dump_expression(vinit, node_counter);
    }
  }
}

void AST_Dumper::dump_constant_declaration(const IDeclaration *decl,
                                           int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_annotation_declaration(const IDeclaration *decl,
                                             int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dispatch_dump_statement(const IStatement *stat,
                                         int *node_counter) {
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

void AST_Dumper::dump_compound_statement(const IStatement *stat,
                                         int *node_counter) {
  const IStatement_compound *sc = as<IStatement_compound>(stat);
  printf("%i [label=\"block\"];\n", *node_counter);
  int root = *node_counter;
  *node_counter += 1;
  for (int i = 0; i < sc->get_statement_count(); i++) {
    printf("%i -> %i;\n\n", root, *node_counter);
    dispatch_dump_statement(sc->get_statement(i), node_counter);
  }
}

void AST_Dumper::dump_return_statement(const IStatement *stat,
                                       int *node_counter) {
  auto r = as<IStatement_return>(stat);
  printf("%i [label=\"return\"];\n", *node_counter);
  *node_counter += 1;
  printf("%i -> %i;\n\n", *node_counter - 1, *node_counter);
  dispatch_dump_expression(r->get_expression(), node_counter);
}

void AST_Dumper::dump_break_statement(const IStatement *stat,
                                      int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_do_while_statement(const IStatement *stat,
                                         int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_expression_statement(const IStatement *stat,
                                           int *node_counter) {
  const IStatement_expression *e = as<IStatement_expression>(stat);
  dispatch_dump_expression(e->get_expression(), node_counter);
}

void AST_Dumper::dump_switch_statement(const IStatement *stat,
                                       int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_continue_statement(const IStatement *stat,
                                         int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_for_statement(const IStatement *stat, int *node_counter) {
  auto f = as<IStatement_for>(stat);
  printf("%i [label=\"for\"];\n", *node_counter);
  int root = *node_counter;
  *node_counter += 1;
  printf("%i -> %i;\n\n", root, *node_counter);
  dispatch_dump_statement(f->get_init(), node_counter);
  printf("%i -> %i;\n\n", root, *node_counter);
  dispatch_dump_expression(f->get_condition(), node_counter);
  printf("%i -> %i;\n", root, *node_counter);
  dispatch_dump_expression(f->get_update(), node_counter);
  printf("%i -> %i;\n", root, *node_counter);
  dispatch_dump_statement(f->get_body(), node_counter);
}

void AST_Dumper::dump_while_statement(const IStatement *stat,
                                      int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_case_statement(const IStatement *stat,
                                     int *node_counter) {
  NOT_IMPLEMENTED;
}

void AST_Dumper::dump_if_statement(const IStatement *stat, int *node_counter) {
  auto f = as<IStatement_if>(stat);
  printf("%i [label=\"if\"];\n", *node_counter);
  int root = *node_counter;
  *node_counter += 1;
  printf("%i -> %i;\n", root, *node_counter);
  dispatch_dump_expression(f->get_condition(), node_counter);
  printf("%i -> %i;\n", root, *node_counter);
  dispatch_dump_statement(f->get_then_statement(), node_counter);
  auto el = f->get_else_statement();
  if (el != nullptr) {
    printf("%i -> %i;\n", root, *node_counter);
    dispatch_dump_statement(f->get_else_statement(), node_counter);
  }
}

void AST_Dumper::dump_declaration_statement(const IStatement *stat,
                                            int *node_counter) {
  dispatch_dump_declaration(as<IStatement_declaration>(stat)->get_declaration(),
                            node_counter);
}

void AST_Dumper::dispatch_dump_expression(const IExpression *exp,
                                          int *node_counter) {
  switch (exp->get_kind()) {
  case IExpression::EK_INVALID:
    break;
  case IExpression::EK_LITERAL:
    dump_expression_literal(exp, node_counter);
    break;
  case IExpression::EK_REFERENCE:
    dump_expression_reference(exp, node_counter);
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

const char *AST_Dumper::value_to_string(const IValue *l) {
  std::string *s = new std::string();
  switch (l->get_kind()) {
  case IValue::VK_BAD:
    break;
  case IValue::VK_BOOL:
    *s = std::to_string(as<IValue_bool>(l)->get_value());
    break;
  case IValue::VK_INT:
    *s = std::to_string(as<IValue_int>(l)->get_value());
    break;
  case IValue::VK_ENUM:
    *s = std::to_string(as<IValue_enum>(l)->get_value());
    break;
  case IValue::VK_FLOAT:
    *s = std::to_string(as<IValue_float>(l)->get_value());
    break;
  case IValue::VK_DOUBLE:
    *s = std::to_string(as<IValue_double>(l)->get_value());
    break;
  case IValue::VK_STRING:
    *s = (as<IValue_string>(l)->get_value());
    break;
  case IValue::VK_VECTOR: {
    *s = "[";
    const IValue_vector *v = as<IValue_vector>(l);
    for (int i = 0; i < v->get_component_count(); i++) {
      auto saba = v->get_value(i);
      if (i != 0) {
        *s += ",";
      }
      *s += value_to_string(saba);
      *s += "\\n";
    }
    *s += "]";
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
    *s = "R: " +
         std::to_string(as<IValue_rgb_color>(l)->get_value(0)->get_value()) +
         "\\n G: " +
         std::to_string(as<IValue_rgb_color>(l)->get_value(1)->get_value()) +
         "\\n B: " +
         std::to_string(as<IValue_rgb_color>(l)->get_value(2)->get_value());
    break;
  case IValue::VK_STRUCT: {
    const IValue_struct *v = as<IValue_struct>(l);
    const IType_struct *st = as<IType_struct>(v->get_type());
    *s = std::string(st->get_symbol()->get_name()) + "{";
    const ISymbol *sym;
    const IType *type;
    for (int i = 0; i < st->get_field_count(); ++i) {
      st->get_field(i, type, sym);
      if (i != 0) {
        *s += ",";
      }
      *s += "\\n";
      *s += sym->get_name();
      *s += " : ";
      *s += value_to_string(v->get_field(sym));
    }
    *s += "}";
    break;
  }
  case IValue::VK_INVALID_REF: {
    const IType *t = as<IValue_invalid_ref>(l)->get_type();
    *s = std::string(type_to_string(t)) + "()";
    break;
  }
  case IValue::VK_TEXTURE:
    // s = std::to_string(as<IValue_texture>(l)->get_value());
    NOT_IMPLEMENTED;
    break;
  case IValue::VK_LIGHT_PROFILE:
    NOT_IMPLEMENTED;
    *s = std::to_string(as<IValue_bool>(l)->get_value());
    break;
  case IValue::VK_BSDF_MEASUREMENT:
    NOT_IMPLEMENTED;
    *s = std::to_string(as<IValue_bool>(l)->get_value());
    break;
  }
  return s->c_str();
}

void AST_Dumper::dump_expression_literal(const IExpression *pExpression,
                                         int *pInt) {
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
    s = std::to_string(as<IValue_float>(l)->get_value());
    break;
  case IValue::VK_DOUBLE:
    s = std::to_string(as<IValue_double>(l)->get_value());
    break;
  case IValue::VK_STRING:
    s = "\\\"" + std::string((as<IValue_string>(l)->get_value())) + "\\\"";
    break;
  case IValue::VK_VECTOR: {
    s = "[";
    const IValue_vector *v = as<IValue_vector>(l);
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
    s = "R : " +
        std::to_string(as<IValue_rgb_color>(l)->get_value(0)->get_value()) +
        "\\n G : " +
        std::to_string(as<IValue_rgb_color>(l)->get_value(1)->get_value()) +
        "\\n B : " +
        std::to_string(as<IValue_rgb_color>(l)->get_value(2)->get_value());
    break;
  case IValue::VK_STRUCT: {
    const IValue_struct *v = as<IValue_struct>(l);
    const IType_struct *st = as<IType_struct>(v->get_type());
    s = std::string(st->get_symbol()->get_name()) + "{";
    const ISymbol *sym;
    const IType *type;
    for (int i = 0; i < st->get_field_count(); ++i) {
      st->get_field(i, type, sym);
      if (i != 0) {
        s += ",";
      }
      s += "\\n";
      s += sym->get_name();
      s += " : ";
      s += value_to_string(v->get_field(sym));
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
  printf("%i [label=\"%s\"];\n", *pInt, s.c_str());
  *pInt += 1;
}

void AST_Dumper::dump_expression_let(const IExpression *pExpression,
                                     int *pInt) {
  const IExpression_let *l = as<IExpression_let>(pExpression);
  printf("%i [label=\"let\"];\n", *pInt);
  int root = *pInt;
  *pInt += 1;
  for (int i = 0; i < l->get_declaration_count(); i++) {
    printf("%i -> %i;\n", root, *pInt);
    dispatch_dump_declaration(l->get_declaration(i), pInt);
  }
  printf("%i -> %i;\n", root, *pInt);
  dispatch_dump_expression(l->get_expression(), pInt);
}

void AST_Dumper::dump_expression_conditional(const IExpression *pExpression,
                                             int *pInt) {
  auto conditional = as<IExpression_conditional>(pExpression);
  printf("%i [label=\":?\"];\n", *pInt);
  int root = *pInt;
  *pInt += 1;
  printf("%i -> %i;\n", root, *pInt);
  dispatch_dump_expression(conditional->get_condition(), pInt);
  printf("%i -> %i;\n", root, *pInt);
  dispatch_dump_expression(conditional->get_true(), pInt);
  printf("%i -> %i;\n", root, *pInt);
  dispatch_dump_expression(conditional->get_false(), pInt);
}

void AST_Dumper::dump_expression_unary(const IExpression *pExpression,
                                       int *pInt) {
  auto un = as<IExpression_unary>(pExpression);
  printf("%i [label=\"%s\"];\n", *pInt,
         unary_operator_to_string(un->get_operator()));
  int root = *pInt;
  *pInt += 1;
  printf("%i -> %i;\n", root, *pInt);
  dispatch_dump_expression(un->get_argument(), pInt);
}

void AST_Dumper::dump_expression_reference(const IExpression *pExpression,
                                           int *pInt) {
  const IExpression_reference *exp = as<IExpression_reference>(pExpression);
  printf("%i [label=\"%s\"];\n", *pInt,
         exp->get_definition()->get_symbol()->get_name());
  *pInt += 1;
}

void AST_Dumper::dump_expression_binary(const IExpression *pExpression,
                                        int *pInt) {
  auto bin = as<IExpression_binary>(pExpression);
  printf("%i [label=\"%s\"];\n", *pInt,
         binary_operator_to_string(bin->get_operator()));
  int root = *pInt;
  *pInt += 1;
  printf("%i -> %i;\n", root, *pInt);
  dispatch_dump_expression(bin->get_left_argument(), pInt);
  printf("%i -> %i;\n", root, *pInt);
  dispatch_dump_expression(bin->get_right_argument(), pInt);
}

void AST_Dumper::dump_expression_call(const IExpression *pExpression,
                                      int *pInt) {
  const IExpression_call *c = as<IExpression_call>(pExpression);
  auto calle = as<IExpression_reference>(c->get_reference());
  auto calle_name = calle->get_name()
                        ->get_qualified_name()
                        ->get_definition()
                        ->get_symbol()
                        ->get_name();
  printf("%i [label=\"%s(", *pInt, calle_name);
  for (int i = 0; i < c->get_argument_count(); ++i) {
    if (i != 0) {
      printf(",");
    }
    printf("\\n");
    const IArgument *arg = c->get_argument(i);
    const IExpression *exp = arg->get_argument_expr();
    printf("%s", type_to_string(exp->get_type()));
  }
  printf(")\"];\n");
  int root = *pInt;
  *pInt += 1;
  for (int i = 0; i < c->get_argument_count(); ++i) {
    const IArgument *arg = c->get_argument(i);
    const IExpression *exp = arg->get_argument_expr();
    printf("%i -> %i;\n", root, *pInt);
    dispatch_dump_expression(exp, pInt);
  }
}

const char *
AST_Dumper::binary_operator_to_string(const IExpression_binary::Operator op) {
  switch (op) {
  case IExpression_binary::OK_SELECT:
    return ".";
  case IExpression_binary::OK_ARRAY_INDEX:
    return "[]";
  case IExpression_binary::OK_MULTIPLY:
    return "*";
  case IExpression_binary::OK_DIVIDE:
    return "/";
  case IExpression_binary::OK_MODULO:
    return "%";
  case IExpression_binary::OK_PLUS:
    return "+";
  case IExpression_binary::OK_MINUS:
    return "-";
  case IExpression_binary::OK_SHIFT_LEFT:
    return "<<";
  case IExpression_binary::OK_SHIFT_RIGHT:
    return ">>";
  case IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT:
    return ">>>";
  case IExpression_binary::OK_LESS:
    return "<";
  case IExpression_binary::OK_LESS_OR_EQUAL:
    return "<=";
  case IExpression_binary::OK_GREATER_OR_EQUAL:
    return ">=";
  case IExpression_binary::OK_GREATER:
    return ">";
  case IExpression_binary::OK_EQUAL:
    return "==";
  case IExpression_binary::OK_NOT_EQUAL:
    return "!=";
  case IExpression_binary::OK_BITWISE_AND:
    return "&";
  case IExpression_binary::OK_BITWISE_XOR:
    return "^";
  case IExpression_binary::OK_BITWISE_OR:
    return "|";
  case IExpression_binary::OK_LOGICAL_AND:
    return "&&";
  case IExpression_binary::OK_LOGICAL_OR:
    return "||";
  case IExpression_binary::OK_ASSIGN:
    return "=";
  case IExpression_binary::OK_MULTIPLY_ASSIGN:
    return "*=";
  case IExpression_binary::OK_DIVIDE_ASSIGN:
    return "/=";
  case IExpression_binary::OK_MODULO_ASSIGN:
    return "%=";
  case IExpression_binary::OK_PLUS_ASSIGN:
    return "+=";
  case IExpression_binary::OK_MINUS_ASSIGN:
    return "-=";
  case IExpression_binary::OK_SHIFT_LEFT_ASSIGN:
    return "<<=";
  case IExpression_binary::OK_SHIFT_RIGHT_ASSIGN:
    return ">>=";
  case IExpression_binary::OK_UNSIGNED_SHIFT_RIGHT_ASSIGN:
    return ">>>=";
  case IExpression_binary::OK_BITWISE_AND_ASSIGN:
    return "&=";
  case IExpression_binary::OK_BITWISE_XOR_ASSIGN:
    return "^=";
  case IExpression_binary::OK_BITWISE_OR_ASSIGN:
    return "|=";
  case IExpression_binary::OK_SEQUENCE:
    return "..";
  }
}

const char *
AST_Dumper::unary_operator_to_string(const IExpression_unary::Operator op) {
  switch (op) {
  case IExpression_unary::OK_BITWISE_COMPLEMENT:
    return "~";
  case IExpression_unary::OK_LOGICAL_NOT:
    return "!";
  case IExpression_unary::OK_POSITIVE:
    return "+";
  case IExpression_unary::OK_NEGATIVE:
    return "-";
  case IExpression_unary::OK_PRE_INCREMENT:
    return "++()";
  case IExpression_unary::OK_PRE_DECREMENT:
    return "--()";
  case IExpression_unary::OK_POST_INCREMENT:
    return "()++";
  case IExpression_unary::OK_POST_DECREMENT:
    return "()--";
  }
}
} // namespace mdl

} // namespace mi
