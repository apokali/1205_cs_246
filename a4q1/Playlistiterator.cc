#include "PlaylistIterator.h"

PlaylistIterator::PlaylistIterator( std::vector<DigitalMedia *>::iterator i, int time_elapsed )
: currIt{i}, SecondsPlayed{time_elapsed} {}

int PlaylistIterator::getElapsedTime() const { return SecondsPlayed; }

// Caller "plays" the item by printing its information to std::cout.
DigitalMedia * PlaylistIterator::operator*() {
    return *currIt;
}

// Adds the duration of the item just played to the total time elapsed so far before moving
// the iterator.
PlaylistIterator PlaylistIterator::operator++() {
    SecondsPlayed += (*currIt)->getDuration();
    ++currIt;
    return *this;
}

bool PlaylistIterator::operator==(const PlaylistIterator &other) const 
{ return ((currIt == other.currIt) && (SecondsPlayed == other.SecondsPlayed)); }

bool PlaylistIterator::operator!=(const PlaylistIterator &other) const 
{ return !((currIt == other.currIt) && (SecondsPlayed == other.SecondsPlayed)); }
