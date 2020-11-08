#include "grid.h"

Grid::~Grid() {
    if ( td != nullptr ) delete td;
    cell_data.clear();
}

void Grid::init( size_t n ) {
    // std::cout << "size:" << n << "\n";
    if ( td != nullptr ) {
        this->~Grid();
    }
    td = new TextDisplay{n};
    
    std::vector<Cell> row_data;
    for ( size_t row = 0; row < n; ++row ) {
        cell_data.emplace_back(row_data);
        for ( size_t col = 0; col < n; ++col ) {
            cell_data[row].emplace_back(Cell{row, col});
        }

    }// for loop

    for ( size_t row = 0; row < n; ++row ) {
        for ( size_t col = 0; col < n; ++col ) {
            // left upper
            if ( (row > 0) && (col > 0) ) cell_data[row][col].attach(&cell_data[row-1][col-1]);
            // up 
            if ( row > 0 ) {
                cell_data[row][col].attach(&cell_data[row-1][col]); 
            }
            // right upper
            if ( (row > 0) && (col < n-1) ) cell_data[row][col].attach(&cell_data[row-1][col+1]);
            // left
            if ( col > 0 ) cell_data[row][col].attach(&cell_data[row][col-1]);
            // right
            if ( col < n-1 ) cell_data[row][col].attach(&cell_data[row][col+1]);
            // left down
            if ( (row < n-1) && (col > 0) ) cell_data[row][col].attach(&cell_data[row+1][col-1]);
            // down
            if ( row < n-1 ) cell_data[row][col].attach(&cell_data[row+1][col]);
            // right down
            if ( (col < n-1) && (row < n-1) ) cell_data[row][col].attach(&cell_data[row+1][col+1]);
        }
    } // for loop
} // Sets up an n x n grid.  Clears old grid, if necessary.

void Grid::turnOn( size_t r, size_t c ) {
    cell_data[c][r].setLiving(); // marks cell
    td->notify(cell_data[c][r]); // notify text display
}  // Marks cell at row r, col c as alive.

void Grid::tick() {
    for ( size_t row = 0; row < cell_data.size(); ++row ) {
        for ( size_t col = 0; col < cell_data.size(); ++col ) {
            cell_data[col][row].reset();
        }
    }

    for ( size_t row = 0; row < cell_data.size(); ++row ) {
        for ( size_t col = 0; col < cell_data.size(); ++col ) {
            cell_data[col][row].notify();
        }
    }
    for ( size_t row = 0; row < cell_data.size(); ++row ) {
        for ( size_t col = 0; col < cell_data.size(); ++col ) {
            cell_data[col][row].recalculate();
        }
    }
    for ( size_t row = 0; row < cell_data.size(); ++row ) {
        for ( size_t col = 0; col < cell_data.size(); ++col ) {
            td->notify(cell_data[col][row]);
        }
    }
}   // Next tick of the simulation.

std::ostream & operator<<( std::ostream & out, const Grid & g ) {
    out << *(g.td);
    return out;
}
