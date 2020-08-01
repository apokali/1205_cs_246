#include "eval.h"


std::string EvalVisitor::visit(AddNode &node) {
    int result = std::stoi(node.getLeft().accept(*this)) + std::stoi(node.getRight().accept(*this));
    return std::to_string(result);
}
std::string EvalVisitor::visit(SubNode &node) {
    int result = std::stoi(node.getLeft().accept(*this)) - std::stoi(node.getRight().accept(*this));
    return std::to_string(result);
}
std::string EvalVisitor::visit(MulNode &node) {
    int result = std::stoi(node.getLeft().accept(*this)) * std::stoi(node.getRight().accept(*this));
    return std::to_string(result);
}
std::string EvalVisitor::visit(DivNode &node) {
    int result = std::stoi(node.getLeft().accept(*this)) / std::stoi(node.getRight().accept(*this));
    return std::to_string(result);
}

std::string EvalVisitor::visit(NumNode &node) {
    return node.getNum();
}

