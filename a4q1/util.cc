#include "util.h"

void getString( std::istream & in, std::string & s, const char * fieldType ) {
    if ( !getline( in, s ) ) {
        std::string type = fieldType;
        std::string error_message = "failed to read in " + type;
        throw std::runtime_error(error_message);
    }

    // *** If getline fails to obtain the necessary argument, raise
    // *** std::runtime_error initialized with the fiedlType parameter passed in.

} // getString

void getInteger( std::istream & in, int & i, const char * fieldType ) {
    std::string s;
    if ( !getline( in, s ) ) {
        std::string type = fieldType;
        std::string error_message = "failed to read in " + type;
        throw std::runtime_error(error_message);
    }
    int len = s.length();
    for ( int i = 0; i < len; ++i ) {
        if ( !isdigit(s[i])) {
            std::string type = fieldType;
            std::string error_message = "failed to read in " + type;
            throw std::runtime_error(error_message);
        }
    }

    // *** If std::stoi fails, or getline fails to obtain the necessary argument, raise
    // *** std::runtime_error initialized with the fiedlType parameter passed in.
    i = std::stoi(s);
} // getInteger
