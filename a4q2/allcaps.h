#ifndef _ALLCAPS_
#define _ALLCAPS_H_
#include "decorator.h"
#include <string>

class TextProcessor;

class Allcaps: public Decorator {
    std::istream *source;
public:
    Allcaps( TextProcessor *component );
    void setSource(std::istream *inp) override;
    std::string getWord() override;
};

#endif
