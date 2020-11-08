#include "Song.h"

std::string checkArtist( const std::string & artist ) {
    if ( artist.length() < 1 ) throw std::length_error("artist has length < 1");
    else return artist;
} // checkArtist

Song::Song( const std::string & key, const std::string & title, int duration,
    const std::string & artist, const std::string & album, const std::string & genre )
: DigitalMedia{ key, title, duration }, artist{artist}, album{album}, genre{genre} {
    if ( artist.length() < 1 ) throw std::length_error("artist has length < 1");
}

Song::~Song() {}

void Song::print( std::ostream & out ) {
    out << *this;
}

const std::string & Song::getArtist() const { return artist; }

const std::string & Song::getAlbum() const { return album; }

const std::string & Song::getGenre() const { return genre; }

std::ostream & operator<<( std::ostream & out, const Song & s ) {
    out << "(" << s.getKey() << ", ";
    out << "\"" << s.getTitle() << "\", ";
    out << "\"" << s.getAlbum() << "\", ";
    out << "\"" << s.getArtist() << "\", ";
    out << s.getDuration() << ", ";
    out << "\"" << s.getGenre() << "\")";
    return out;
}

std::istream & operator>>( std::istream & in, Song & s ) {
    std::string key,title, artist, album, genre;
    int duration;
    getString( in, key, "key" );
    getString( in, title, "title" );
    getInteger( in, duration, "duration" );
    getString( in, artist, "artist" );
    getString( in, album, "album" );
    getString( in, genre, "genre" );
    Song temp{key, title, duration, artist, album, genre};
    s = std::move(temp);
    return in;
}
