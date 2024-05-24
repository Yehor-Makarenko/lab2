#include "ast_evaluator.hh"
#include "../utils/errors.hh"

namespace ast {

int32_t ASTEvaluator::visit(const IntegerLiteral &literal) {
  return literal.value;
}

int32_t ASTEvaluator::visit(const BinaryOperator &binop) {
  int32_t left = binop.get_left().accept(*this);
  int32_t right = binop.get_right().accept(*this);
  switch(binop.op) {
    case 0:
      return left + right;
    case 1:
      return left - right;
    case 2:
      return left * right;
    case 3:
      return left / right;
    case 4:
      return 1 ? left == right : 0;
    case 5:
      return 1 ? left != right : 0;
    case 6:
      return 1 ? left < right : 0;
    case 7:
      return 1 ? left <= right : 0;
    case 8:
      return 1 ? left > right : 0;
    case 9:
      return 1 ? left >= right: 0;    
  }  
}

int32_t ASTEvaluator::visit(const Sequence &seqExpr) {
  const auto exprs = seqExpr.get_exprs();
  int32_t lastValue = 0;
  if (exprs.size() == 0) {
    utils::error("Empty sequence");
  }
  for (auto expr: exprs) {  
    lastValue = expr->accept(*this);
  }  
  return lastValue;
}

int32_t ASTEvaluator::visit(const IfThenElse &ite) {
  int32_t condition = ite.get_condition().accept(*this);
  if (condition != 0) {
    return ite.get_then_part().accept(*this);
  } else {
    return ite.get_else_part().accept(*this);
  }
}

int32_t ASTEvaluator::visit(const StringLiteral &literal) {
  utils::error("Unsupported node");
}

int32_t ASTEvaluator::visit(const Let &let) {
  utils::error("Unsupported node");
}

int32_t ASTEvaluator::visit(const Identifier &id) {
  utils::error("Unsupported node");
}

int32_t ASTEvaluator::visit(const VarDecl &decl) {
  utils::error("Unsupported node");
}

int32_t ASTEvaluator::visit(const FunDecl &decl) {
  utils::error("Unsupported node");
}

int32_t ASTEvaluator::visit(const FunCall &call) {
  utils::error("Unsupported node");
}

int32_t ASTEvaluator::visit(const WhileLoop &loop) {
  utils::error("Unsupported node");
}

int32_t ASTEvaluator::visit(const ForLoop &loop) {
  utils::error("Unsupported node");
}

int32_t ASTEvaluator::visit(const Break &brk) {
  utils::error("Unsupported node");
}

int32_t ASTEvaluator::visit(const Assign &assign) {
  utils::error("Unsupported node");
}

} // namespace ast
