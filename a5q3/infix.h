#ifndef INFIX_H
#define INFIX_H
#include <vector>
#include <string>
#include <iostream>

#include "expvisitor.h"
#include "expression.h"

class ExpVisitor;

class InfixVisitor:public ExpVisitor {
    public:
    virtual std::string visit(AddNode &node) override;
    virtual std::string visit(SubNode &node) override;
    virtual std::string visit(MulNode &node) override;
    virtual std::string visit(DivNode &node) override;
    virtual std::string visit(NumNode &node) override;
};



#endif
