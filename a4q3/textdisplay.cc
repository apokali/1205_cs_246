#include "textdisplay.h"

TextDisplay::TextDisplay( size_t n ) {
    std::vector<char> row_data;
    
    for ( size_t row = 0; row < n; ++row ) {
        theDisplay.emplace_back(row_data);
        for ( size_t col = 0; col < n; ++col ) {
            theDisplay[row].emplace_back('_');
        }
    }
}

void TextDisplay::notify( Subject & whoNotified ) {
    size_t row =  whoNotified.getInfo().row;
    size_t col =  whoNotified.getInfo().col;
    //  std::cout << "row:" << row << "\n";
    // std::cout << "col:" << col << "\n";

    if ( whoNotified.getInfo().state == State::Alive ) {
        theDisplay[row][col] = 'X';
    }
    if ( whoNotified.getInfo().state == State::Dead ) {
        theDisplay[row][col] = '_';
    }
    
}

void TextDisplay::notify() {}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td) {
    for ( size_t row = 0; row < td.theDisplay.size(); ++row ) {
        for ( size_t col = 0; col < td.theDisplay.size(); ++col) {
            out << td.theDisplay[row][col];
        }
        out << std::endl;
    }

    return out;
}
