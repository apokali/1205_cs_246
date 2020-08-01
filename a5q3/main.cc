#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "expression.h"
#include "infix.h"
#include "eval.h"

int main() {
    std::string one_line;

    while (getline(std::cin, one_line)) {
        std::vector<std::shared_ptr<ExpNode>> exp_stack;     // stack
        InfixVisitor infix;
        EvalVisitor eval;

        std::istringstream ss{one_line};
        std::string s;
        while (ss>> s) {
            if ( (s == "+" || s == "-" || s == "*" || s == "/")) {
                if (exp_stack.size() >= 2) {
                    auto right = exp_stack.back();
                    exp_stack.pop_back();
                    auto left = exp_stack.back();
                    exp_stack.pop_back();
                    //std::cout << "after: count" <<exp_stack.size() <<"\n";
                    if ( s=="+") exp_stack.emplace_back(std::make_shared<AddNode>(left, right));
                    else if ( s=="-") exp_stack.emplace_back(std::make_shared<SubNode>(left, right));
                    else if ( s=="*") exp_stack.emplace_back(std::make_shared<MulNode>(left, right));
                    else exp_stack.emplace_back(std::make_shared<DivNode>(left, right));
                } else {
                    std::cerr << "Invalid Expression!" << std::endl;
                }
            } else {
                exp_stack.emplace_back(std::make_shared<NumNode>(s));
            }
        }//while
        if (exp_stack.size()==1) {
            for ( auto e:exp_stack ) {
                std::cout << e->accept(infix)<< " = " << e->accept(eval) << std::endl;
            } //print the only expression
        } else {
            std::cerr << "Invalid Expression!" << std::endl;
        }
    }//while
}
