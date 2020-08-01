#ifndef EXPVISITOR_H
#define EXPVISITOR_H
#include "expression.h"

class AddNode;
class SubNode;
class MulNode;
class DivNode;
class NumNode;

class ExpVisitor {
    public:
    virtual std::string visit(AddNode &node) = 0;
    virtual std::string visit(SubNode &node) = 0;
    virtual std::string visit(MulNode &node) = 0;
    virtual std::string visit(DivNode &node) = 0;
    virtual std::string visit(NumNode &node) = 0;
    virtual ~ExpVisitor();
};


#endif
