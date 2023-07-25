#include "level2.h"

Level2::Level2(string colour, Computer *component) : Decorator{colour, component} {} 

Move Level2::turnMove(int x, int y, int z, int w, Board& b)  {
    // int rstartX = rand() % 7; 
    // int rstartY = rand() % 7; 
    // int random = 0; 
    // pair<int, int> newMove; 
    // vector<pair<int, int>> moves; 

    // while (true) {
    //     if (b.getPiece(rstartX, rstartY)->getColor() == getColour()) {
    //         moves = b.getPiece(rstartX, rstartY)->getPossibleMoves(b.getPiece(rstartX, rstartY), b, rstartX, rstartY); 
    //         break; 
    //     }
    //     else {
    //         rstartX = rand() % 7; 
    //         rstartY = rand() % 7; 
    //     }

    // }

    // random = rand() % (moves.size()); 
    // newMove = moves[random]; 

    // return Move{rstartX, rstartY, newMove.first, newMove.second, b.getPiece(rstartX, rstartY)->isValidMove(rstartX, rstartY, newMove.first, newMove.second), b.getPiece(rstartX, rstartY)}; 
    return Move{0, 0, 0, 0, false, b.getPiece(0, 0)};
}
