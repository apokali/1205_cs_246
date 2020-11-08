#include "Library.h"

Library::Library() {
    media = new std::map<std::string, DigitalMedia *>;
}   // Creates empty library.

Library::~Library() {
    if ( media != nullptr ) {
        for (auto &data: *media) {
            delete data.second;
        }
    }
    delete media;
}   // Destroys all items in library.

LibraryIterator Library::begin() { return LibraryIterator{media->begin()}; }       // Iterator set to beginning of library contents.

LibraryIterator Library::end() { return LibraryIterator{media->end()}; }           // Iterator set past end of library contents.

// Stores item, indexed by key. If key already exists, raises std::logic_error
// and specifies as the message that "key KKKK already exists in library".
void Library::add( DigitalMedia * m ) {
    if ( media->count(m->getKey()) == 1 ) {
        std::string error_message = "key " + m->getKey() +  " already exists in library";
    }
    (*media)[m->getKey()] = m;
}    

void Library::remove( std::string key ) {
    if ( media->count(key) == 1 ) media->erase(key);
}  // Remove item if find key value else does nothing.

// Returns pointer to item, or nullptr if not there.
DigitalMedia * Library::find( std::string key ) {
    if ( media->count(key) == 1 ) return (*media)[key];
    else return nullptr;
}

// Returns modified output stream. Stream contains the header "Library:\n" and the library
// contents, ordered by key. Each object is output using the appropriate output operator
// for the underlying object type, one per line and starting with a tab character.
std::ostream & operator<<( std::ostream & out, Library & library ) {
    out << "Library:\n";
    for (auto &data: *(library.media) ) { // already a friend
        out << "\t";
        (data.second)->print(out);
        out << "\n";
    }
    return out;
}

// Returns modified input stream. Contents of library modified with information read in, 
// where the character 't' on a line specifies a TV show is to be read next, while 's'
// indicates that a Song is to be read in next. Reading continues until EOF is reached
// or an exception is raised. Raises std::runtime_error( "invalid media type" ) if doesn't
// get either 's' or 't'.
std::istream & operator>>( std::istream & in, Library & library ) {
    std::string type;
    while ( getline( in, type ) ) {
        if ( type == "s")  {
            Song temp{ "S01", "Great beat and you can dance to it", 183, "Too cool", "I'd give it a 10!", "Eclectic" };
            in >> temp;
            library.add( new Song{temp} );
        } else if ( type == "t" ) {
            TV temp{ "TV01", "Somewhere far away, and long ago", 2580, 1, 1, "Amazing New Show" };
            in >> temp;
            library.add( new TV{temp} );
        } else {
            throw std::runtime_error( "invalid media type" );
            break;
        }
    }
    return in;
}
