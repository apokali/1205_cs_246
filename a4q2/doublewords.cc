#include "doublewords.h"

Doublewords::Doublewords(  TextProcessor* component )
: Decorator{component}, source{0}, count{1}, last{""} {}

void Doublewords::setSource( std::istream *inp ) { component->setSource(inp); }

std::string Doublewords::getWord() {
    if ( count % 2 != 0  ) {
        last = component->getWord();
        ++count;
        return last;
    } else {
        ++count;
        return last;
    }
}
