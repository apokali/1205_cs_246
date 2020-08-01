#ifndef EVAL_H
#define EVAL_H

#include "expvisitor.h"

class EvalVisitor:public ExpVisitor {
    public:
    virtual std::string visit(AddNode &node) override;
    virtual std::string visit(SubNode &node) override;
    virtual std::string visit(MulNode &node) override;
    virtual std::string visit(DivNode &node) override;
    virtual std::string visit(NumNode &node) override;
};

#endif
