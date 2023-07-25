#include "level4.h"

Move Level4::turnMove(int x, int y, int z, int w, Board& b) {
    // return Move{0, 0, 0, 0, b.getPiece(0, 0)->isValidMove(0, 0, 0, 0), b.getPiece(0, 0)}; 
    return Move{0, 0, 0, 0, false, b.getPiece(0, 0)};
} 
