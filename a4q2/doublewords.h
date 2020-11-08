#ifndef _DOUBLEWORDS_H_
#define _DOUBLEWORDS_H_
#include "decorator.h"
#include <string>

class TextProcessor;

class Doublewords: public Decorator {
    std::istream *source;
    int count;
    std::string last;
public:
    Doublewords( TextProcessor * component );
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
