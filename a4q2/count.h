#ifndef _COUNT_
#define _COUNT_H_
#include "decorator.h"
#include <string>

class TextProcessor;

class Count: public Decorator {
    std::istream *source;
    int count;
    char c;
public:
    Count( char c, TextProcessor *component );
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
