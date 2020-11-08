#include "LibraryIterator.h"

LibraryIterator::LibraryIterator( std::map<std::string, DigitalMedia *>::iterator i ): currIt{i} {}

DigitalMedia * LibraryIterator::operator*() { return currIt->second; }

LibraryIterator LibraryIterator::operator++() { 
    ++currIt; // special calling ++ iterator
    return *this;
}

bool LibraryIterator::operator==(const LibraryIterator &other) const { return currIt == other.currIt; }

bool LibraryIterator::operator!=(const LibraryIterator &other) const { return !(*this == other); }
