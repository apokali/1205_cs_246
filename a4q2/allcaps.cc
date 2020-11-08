#include "allcaps.h"

Allcaps::Allcaps( TextProcessor *component )
: Decorator{component}, source{0} {}

void Allcaps::setSource(std::istream *inp) { component->setSource(inp); }

std::string Allcaps::getWord() {
    std::string last = component->getWord();
    std::string result;
    int len = last.length();
    for ( int i = 0; i < len; ++i ) {
        if ( (last[i]>='a') && (last[i]<='z') ) {
            int letter = last[i] - 32;
            char l = letter;
            result += l;
        } else {
            result += last[i];
        }
    }
    return result;
}

