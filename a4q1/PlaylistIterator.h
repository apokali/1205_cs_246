#ifndef _PLAYLIST_ITERATOR_
#define _PLAYLIST_ITERATOR_

#include <string>
#include <vector>
#include "Playlist.h"
#include "DigitalMedia.h"

class Playlist; // forward declarations
class DigitalMedia;

class PlaylistIterator {
    friend class Playlist;
    std::vector<DigitalMedia *>::iterator currIt;
    int SecondsPlayed;
    explicit PlaylistIterator( std::vector<DigitalMedia *>::iterator i, int time_elapsed );

public:
    int getElapsedTime() const;   

    // Caller "plays" the item by printing its information to std::cout.
    DigitalMedia * operator*();

    // Adds the duration of the item just played to the total time elapsed so far before moving
    // the iterator.
    PlaylistIterator operator++();

    bool operator==(const PlaylistIterator &other) const;
    bool operator!=(const PlaylistIterator &other) const; 
};

#endif
