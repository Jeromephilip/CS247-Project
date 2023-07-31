#include "level2.h"

Level2::Level2(string colour, bool isComputer) : Computer{colour, isComputer} {}

Move Level2::turnMove(int x, int y, int z, int w, Board& b)  {
   srand(time(NULL));
   vector<pair<Piece*, pair<int, int>>> pieces; 
   pieces = getPieces(b); 
   /*
    for (int i = 0; i < pieces.size(); i++) {
      cout << "These are our pieces: " << pieces[i].first->getType() << " (" << pieces[i].second.first << ", " << pieces[i].second.second << ")" << endl;
    }*/

   // Level 2: prefers capturing moves and checks over other moves.
   int random = 0; 
   pair<int, int> newMove; 
   vector<pair<int, int>> moves; 

   for (size_t i = 0; i < pieces.size(); i++){
      cout << "Inside for loop " << i << endl;
      if (pieces[i].first->getPossibleCaptures(b, pieces[i].second.first, pieces[i].second.second).size() != 0) {
         random = rand() % (pieces[i].first->getPossibleCaptures(b, pieces[i].second.first, pieces[i].second.second).size()); 
         newMove = pieces[i].first->getPossibleCaptures(b, pieces[i].second.first, pieces[i].second.second)[random]; 
         return Move{pieces[i].second.first, pieces[i].second.second, newMove.first, newMove.second, true, pieces[i].first}; 
      }
   }
   cout << "There are no possible captures" << endl;
   // Seed the random number generator with the current time
    srand(time(NULL));
    
    int rstartX = rand() % 8; 
    int rstartY = rand() % 8; 
    random = 0; 
    //pair<int, int> newMove; 
    //vector<pair<int, int>> moves; 

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
    cout << "Moving: " << b.getPiece(rstartX, rstartY)->getType() << endl;
    random = rand() % (moves.size()); 
    newMove = moves[random]; 

    return Move{rstartX, rstartY, newMove.first, newMove.second, b.getPiece(rstartX, rstartY)->isValidMove(b, rstartX, rstartY, newMove.first, newMove.second), b.getPiece(rstartX, rstartY)}; 

/*
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
    newMove = moves[random]; */

    //return Move{rstartX, rstartY, newMove.first, newMove.second, b.getPiece(rstartX, rstartY)->isValidMove(b, rstartX, rstartY, newMove.first, newMove.second), b.getPiece(rstartX, rstartY)}; 
    //return Move{x, y, x, y, false, nullptr};
}
