#include "DigitalMedia.h"


DigitalMedia::DigitalMedia( const std::string & key, const std::string & title, int duration )
: key{key}, title{title}, duration{duration} {
    if ( key.length() < 1 ) throw std::length_error("key has length < 1");
    if ( title.length() < 1 ) throw std::length_error("title has length < 1");
    if ( duration < 1 ) throw std::invalid_argument("duration < 1");
}

DigitalMedia::~DigitalMedia() {}

void print( std::ostream & out ) {}

const std::string & DigitalMedia::getKey() const { return key; }

const std::string & DigitalMedia::getTitle() const { return title; }

int DigitalMedia::getDuration() const { return duration; } 
