#ifndef _LIBRARY_ITERATOR
#define _LIBRARY_ITERATOR

#include <string>
#include <map>

class Library; // forward declarations
class DigitalMedia;

class LibraryIterator {
    friend class Library;
    std::map<std::string, DigitalMedia *>::iterator currIt;

    explicit LibraryIterator( std::map<std::string, DigitalMedia *>::iterator i );  // Private constructor

public:
    DigitalMedia * operator*();
    LibraryIterator operator++();
    bool operator==(const LibraryIterator &other) const;
    bool operator!=(const LibraryIterator &other) const;    
};

#endif
