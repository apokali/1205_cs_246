#ifndef _DIGITAL_MEDIA
#define _DIGITAL_MEDIA

#include <string>
#include <iostream>
#include <stdexcept> // std::length_error, std::invalid_argument, std::runtime_error
#include "util.h"

class DigitalMedia {
    std::string key, title;
    int duration;
public:
    // Sets key, title and duration information.
    // Raises: std::length_error if key.length() < 1 with the error message: "key has length < 1"
    //         std::length_error if title.length() < 1 with the error message: "title has length < 1"
    //         std::invalid_argument if duration < 1 with the error message: "duration < 1"
    // (checks are made in order listed)
    DigitalMedia( const std::string & key, const std::string & title, int duration );
    virtual ~DigitalMedia();

    // Concrete subclasses use this to invoke their output operator so that Library
    // container can successfully print its contents using the iterator.
    virtual void print( std::ostream & out ) = 0;

    const std::string & getKey() const;
    const std::string & getTitle() const;
    int getDuration() const;
};

#endif
