#include "count.h"

Count::Count(  char c, TextProcessor *component )
: Decorator{component}, source{0}, count{1}, c{c} {}

void Count::setSource(std::istream *inp) { component->setSource(inp); }

std::string Count::getWord() {
    std::string last = component->getWord();
    int len = last.length();
    std::string result;
    for ( int i = 0; i < len; ++i ) {
        if ( last[i] == c ) {
            result += std::to_string(count);
            ++count;
        } else {
            result += last[i];
            
        }
    }
    return result;
}
