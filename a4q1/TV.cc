#include "TV.h"


TV::TV( const std::string & key, const std::string & title, int duration,
    int episode, int season, const std::string & series )
: DigitalMedia{ key, title, duration }, episode{episode}, season{season}, series{series} {
    if ( episode < 1 ) throw std::invalid_argument("episode < 1");
    if ( season < 1 ) throw std::invalid_argument("season < 1");
    if ( series.length() < 1 ) throw std::length_error("series has length < 1");
}
// contructor
TV::~TV() {}

void TV::print( std::ostream & out ) {
    out << *this;
}

int TV::getEpisode() const { return episode; }

int TV::getSeason() const { return season; }

const std::string & TV::getSeries() const { return series; }

// Returns modified output stream. Outputs (key, "series" S<season>E<episode> "title", duration).
// (Explicitly surrounds strings that might have whitespace within with double-quotation marks.
// Season number and episode number have a default width of 2, and must start with '0' if < 10.)
std::ostream & operator<<( std::ostream & out, const TV & t ) {
    out << "(" << t.getKey() << ", ";
    out << "\"" << t.getSeries() << "\" ";
    out << "S";
    if ( t.getSeason() < 10) out << "0";
    out << t.getSeason() << "E";
    if ( t.getEpisode() < 10 ) out << "0";
    out << t.getEpisode() << " ";
    out << "\"" << t.getTitle() << "\", ";
    out << t.getDuration() << ")";
    return out;
}

// Returns modified input stream. Contents of t over-written with information read in, where
// format is "key\ntitle\nduration\nseason\nepisode\nseries\n". 
// Raises std::runtime_error if fails to obtain any of the elements with the message 
// "failed to read in XXX", where XXX is replaced by one of: key, title, duration, season, episode,
// or series or if duration, season, or episode cannot be successfully converted to an int.
// Also follows the exception raise rules for the constructor.
std::istream & operator>>( std::istream & in, TV & t ) {
    std::string key, title, series;
    int duration, episode, season;
    getString( in, key, "key" );
    getString( in, title, "title" );
    getInteger( in, duration, "duration" );
    getInteger( in, season, "season" );
    getInteger( in, episode, "episode" );
    getString( in, series, "series" );
    TV temp{ key, title, duration, episode, season, series };
    t = std::move(temp);
    
    return in;
}
