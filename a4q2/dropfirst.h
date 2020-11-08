#ifndef _DROPFIRST_H_
#define _DROPFIRST_H_
#include "decorator.h"
#include <string>

class TextProcessor;

class Dropfirst: public Decorator {
    std::istream *source;
    int n;
public:
    Dropfirst( int n, TextProcessor *component );
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
