#include "expression.h"

// ===================NumNode==================
NumNode::NumNode(std::string &s): num{s} {}

std::string NumNode::getNum() { return num; }    // getNum()

std::string NumNode::accept(ExpVisitor &v) { return v.visit(*this); }


// ==================AddNode====================
AddNode::AddNode(std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right)
:left{left}, right{right} {} // constructor

ExpNode& AddNode::getLeft() { return *left; }  // getLeft

ExpNode& AddNode::getRight() { return *right; } // getRight

std::string AddNode::accept(ExpVisitor &v) { return v.visit(*this); }


// ==================SubNode====================
SubNode::SubNode(std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right)
:left{left}, right{right} {} // constructor

ExpNode& SubNode::getLeft() { return *left; }

ExpNode& SubNode::getRight() { return *right; }

std::string SubNode::accept(ExpVisitor &v) { return v.visit(*this); }


// ==================MulNode====================
MulNode::MulNode(std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right)
:left{left}, right{right} {} // constructor

ExpNode& MulNode::getLeft() { return *left; }

ExpNode& MulNode::getRight() { return *right; }

std::string MulNode::accept(ExpVisitor &v) { return v.visit(*this); }


// ==================DivNode====================
DivNode::DivNode(std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right)
:left{left}, right{right} {} // constructor

ExpNode& DivNode::getLeft() { return *left; }

ExpNode& DivNode::getRight() { return *right; }

std::string DivNode::accept(ExpVisitor &v) { return v.visit(*this); }

