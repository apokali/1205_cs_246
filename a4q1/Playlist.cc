#include "Playlist.h"

Playlist::Playlist(): TotalSeconds{0} {
    list = new std::vector<DigitalMedia *>;
}

Playlist::~Playlist() {
    if ( list != nullptr ) delete list;
}

void Playlist::reset() {
} // resets the elapsed time back to 0

void Playlist::add( DigitalMedia * m ) {
    list->emplace_back(m);
    TotalSeconds += m->getDuration();
}

void Playlist::remove( DigitalMedia * m ) {
    for ( auto it = list->begin(); it != list->end(); ++it ) { // range-based for loop
        if ( *it == m ) {
            it=list->erase(it);
            TotalSeconds -= m->getDuration();
        } break;
    }
}

PlaylistIterator Playlist::begin() { return PlaylistIterator{list->begin(), 0};  }

PlaylistIterator Playlist::end() { return PlaylistIterator{list->end(), TotalSeconds}; }

int Playlist::getTotalSeconds() const {return TotalSeconds; }

std::ostream & operator<<( std::ostream & out, Playlist & p ) {
    int i = 0;
    for (auto m: *(p.list)) {
        out << "\t";
        if ( i < 10 ) out << "00";
        if ( (i<100) && (i >11)) out << "0";
        out << i << ": ";
        m->print(out);
        out << "\n";
        ++i;
    }
    out << "Total: " << p.TotalSeconds << " seconds\n";
    return out;
}
