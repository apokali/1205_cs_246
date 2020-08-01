#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <vector>
#include <memory>
#include <string>
#include "expvisitor.h"

class ExpVisitor;

class ExpNode {
    public:
    virtual std::string accept(ExpVisitor &v) = 0;
};

class NumNode: public ExpNode {
    std::string num;
    public:
    NumNode(std::string &s); // constructor
    std::string getNum();    // getNum()
    virtual std::string accept(ExpVisitor &v) override;                   // visitor
    
};

// ==================AddNode====================
class AddNode:public ExpNode {
    std::shared_ptr<ExpNode> left, right;
    public:
    AddNode(std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right); // constructor
    ExpNode& getLeft();
    ExpNode& getRight();
    virtual std::string accept(ExpVisitor &v) override;                   // visitor

};

// ==================SubNode====================
class SubNode: public ExpNode{
    std::shared_ptr<ExpNode> left, right;
    public:
    SubNode(std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right); // constructor
    ExpNode& getLeft();
    ExpNode& getRight();
    virtual std::string accept(ExpVisitor &v) override;   
};

// ==================MulNode====================
class MulNode: public ExpNode{
    std::shared_ptr<ExpNode> left, right;
    public:
    MulNode(std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right); // constructor
    ExpNode& getLeft();
    ExpNode& getRight();
    virtual std::string accept(ExpVisitor &v) override;
    
};

// ==================DivNode====================
class DivNode: public ExpNode{
    std::shared_ptr<ExpNode> left, right;
    public:
    DivNode(std::shared_ptr<ExpNode> left, std::shared_ptr<ExpNode> right); // constructor
    ExpNode& getLeft();
    ExpNode& getRight();
    virtual std::string accept(ExpVisitor &v) override;
};

#endif
