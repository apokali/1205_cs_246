#include "cell.h"

Cell::Cell(size_t r, size_t c) {
    info.row = r;
    info.col = c;
    info.state = State::Dead;
    neighbour_alive = 0;
}

void Cell::setLiving() {
    info.state = State::Alive;
} // Marks cell as alive.

void Cell::reset() {
    neighbour_alive = 0;
} // Resets neighbour count to 0.

// Grid calls this to get me to notify my neighbours if I'm alive.
// Also needs to be called when state is set to be alive so displays are notified.
void Cell::notify() {
    if ( info.state == State::Alive ) {
        // std::cout << "row: " << info.row << "\n";
        // std::cout << "col: " << info.col << "\n";
        // std::cout << "live: " << neighbour_alive << "\n";
        this->notifyObservers();
    }
}

// My neighbours will call this to let me know if they're alive.
void Cell::notify( Subject & whoNotified ) {
    if ( whoNotified.getInfo().state == State::Alive ) {
        ++neighbour_alive;
        //  std::cout << "col: " << whoNotified.getInfo().col << "\n";
        //  std::cout << "row: " << whoNotified.getInfo().row << "\n";
        //  std::cout << "col: " << info.col << "\n";
        //  std::cout << "row: " << info.row << "\n";
        //  std::cout << "live:     " << neighbour_alive << "\n\n";
    }
    
}
                                            
// Reassess my living-or-dead status, based on info from neighbours.
void Cell::recalculate() {
    if ( info.state == State::Alive ) {
        // std::cout << "row: " << info.row << "\n";
        //     std::cout << "col: " << info.col << "\n";
        //     std::cout << "live: " << neighbour_alive << "\n";
        if ( (neighbour_alive < 2) || (neighbour_alive > 3) ) {
            info.state = State::Dead;
        }
        
    }
    if ( info.state == State::Dead ) {
        // std::cout << "neighbour_alive " << neighbour_alive << "\n"; 
        if ( neighbour_alive == 3 ) info.state = State::Alive;
    }
}

// Observer calls this to get information about cell.
Info Cell::getInfo() const { return info; }
