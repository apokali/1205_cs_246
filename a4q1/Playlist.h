#ifndef _PLAYLIST_
#define _PLAYLIST_

#include <string>
#include "PlaylistIterator.h"
#include <vector>
#include "DigitalMedia.h"

class DigitalMedia; // forward declaration
class PlaylistIterator;

class Playlist {
    friend std::ostream & operator<<( std::ostream & out, Playlist & p );    
    int TotalSeconds;
    std::vector<DigitalMedia *>* list;

public:
    Playlist();
    virtual ~Playlist();
    void reset(); // resets the elapsed time back to 0
    void add( DigitalMedia * m );
    void remove( DigitalMedia * m );
    PlaylistIterator begin();
    PlaylistIterator end();
    int getTotalSeconds() const;
};

std::ostream & operator<<( std::ostream & out, Playlist & p );

#endif
