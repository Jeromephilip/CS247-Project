#include "level1.h"

Level1::Level1(string colour, bool isComputer) : Computer{colour, isComputer} {} 

Move Level1::turnMove(int x, int y, int z, int w, Board& b) {
    int rstartX = rand() % 7; 
    int rstartY = rand() % 7; 
    int random = 0; 
    pair<int, int> newMove; 
    vector<pair<int, int>> moves; 

    while (true) {
        if (b.getPiece(rstartX, rstartY)->getColor() == getColour()) {
            moves = b.getPiece(rstartX, rstartY)->getPossibleMoves(b, rstartX, rstartY); 
            break; 
        }
        else {
            rstartX = rand() % 7; 
            rstartY = rand() % 7; 
        }

    }

    random = rand() % (moves.size()); 
    newMove = moves[random]; 

    return Move{rstartX, rstartY, newMove.first, newMove.second, b.getPiece(rstartX, rstartY)->isValidMove(b, rstartX, rstartY, newMove.first, newMove.second), b.getPiece(rstartX, rstartY)}; 

}
