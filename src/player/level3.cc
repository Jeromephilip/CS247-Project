#include "level3.h"

Move Level3::turnMove(int x, int y, int z, int w, Board& b) {
    // return Move{0, 0, 0, 0, b.getPiece(0, 0)->isValidMove(0, 0, 0, 0), b.getPiece(0, 0)}; 
    return Move{0, 0, 0, 0, b.getPiece(0, 0)->isValidMove(b, 0, 0, 0, 0), b.getPiece(0, 0)}; 
} 

