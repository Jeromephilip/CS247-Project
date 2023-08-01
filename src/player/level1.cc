#include "level1.h"

Level1::Level1(string colour, bool isComputer) : Computer{colour, isComputer} {} 

Move Level1::turnMove(int x, int y, int z, int w, Board& b) {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    int rstartX = rand() % 8; 
    int rstartY = rand() % 8; 
    int random = 0; 
    pair<int, int> newMove; 
    vector<pair<int, int>> moves; 

    while (true) {
         if (b.getPiece(rstartX, rstartY) != nullptr && b.getPiece(rstartX, rstartY)->getColor() == getColour() && b.getPiece(rstartX, rstartY)->getPossibleMoves(b, rstartX, rstartY).size() != 0) {
            moves = b.getPiece(rstartX, rstartY)->getPossibleMoves(b, rstartX, rstartY); 
            break; 
         }
         else {
            rstartX = rand() % 8; 
            rstartY = rand() % 8; 
         }

    }
    //cout << "Moving: " << b.getPiece(rstartX, rstartY)->getType() << endl;
    random = rand() % (moves.size()); 
    newMove = moves[random]; 

    return Move{rstartX, rstartY, newMove.first, newMove.second, b.getPiece(rstartX, rstartY)->isValidMove(b, rstartX, rstartY, newMove.first, newMove.second), b.getPiece(rstartX, rstartY)}; 
    //return Move{x, y, x, y, false, nullptr};
}
