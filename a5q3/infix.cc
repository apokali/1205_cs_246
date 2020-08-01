#include "infix.h"

std::string InfixVisitor::visit(AddNode &node) {
    std::string result = "(" + node.getLeft().accept(*this) + "+" + node.getRight().accept(*this) + ")";
    return result;
}

std::string InfixVisitor::visit(SubNode &node) {
    std::string result = "(" + node.getLeft().accept(*this) + "-" + node.getRight().accept(*this) + ")";
    return result;
}

std::string InfixVisitor::visit(MulNode &node) {
    std::string result = "(" + node.getLeft().accept(*this) + "*" + node.getRight().accept(*this) + ")";
    return result;
}

std::string InfixVisitor::visit(DivNode &node) {
    std::string result = "(" + node.getLeft().accept(*this) + "/" + node.getRight().accept(*this) + ")";
    return result;
}

std::string InfixVisitor::visit(NumNode &node) {
    return node.getNum();
}


