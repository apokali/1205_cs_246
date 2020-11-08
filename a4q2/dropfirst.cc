#include "dropfirst.h"

Dropfirst::Dropfirst(  int n, TextProcessor *component )
: Decorator{component}, source{source}, n{n} {}

void Dropfirst::setSource(std::istream *inp) { component->setSource(inp); } 

std::string Dropfirst::getWord() {
    std::string last = component->getWord();
    int len = last.length();
    while ( true ) {
        if ( n >= len ) {
            last = component->getWord();
            len = last.length();
        } else break;
    }
    return last.substr(n, len);
}
