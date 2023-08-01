#include "level3.h"

Level3::Level3(string colour, bool isComputer) : Computer{colour, isComputer} {}

Move Level3::turnMove(int x, int y, int z, int w, Board& b) {
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

   vector<Move> possibleChecks {}; 
   vector<Move> possibleCapture {}; 

   // check if the current pieces are themselves in 'check' 
   // if they are in check, move to a random spot 
   for (size_t i = 0; i < pieces.size(); i++) {
       if (b.isCheck(pieces[i].first->getColor(), pieces[i].second.first, pieces[i].second.second)) {
           cout << pieces[i].first->getType() << "(" << pieces[i].second.first  << ", " << pieces[i].second.second << ")" << " is in check" << endl;
           
       }
       for (size_t j = 0; j < pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second).size(); j++) {
            if (b.isCheck(pieces[i].first->getColor(), pieces[i].second.first, pieces[i].second.second)) {
                cout << pieces[i].first->getType() << "(" << pieces[i].second.first  << ", " << pieces[i].second.second << ")" << " is in check" << endl;
                possibleChecks.push_back(Move{pieces[i].second.first, pieces[i].second.second, pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second)[j].first, pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second)[j].second, true, pieces[i].first} );
                //cout << "Running away" << endl; 
            }
        }
        if (possibleChecks.size() != 0) {
            random = rand() % (possibleChecks.size()); 
            cout << "Running away" << endl; 
            return possibleChecks[random]; 
        }
    }



   for (size_t i = 0; i < pieces.size(); i++){
      //cout << "Inside for loop " << i << endl;
      if (pieces[i].first->getPossibleCaptures(b, pieces[i].second.first, pieces[i].second.second).size() != 0) {
         random = rand() % (pieces[i].first->getPossibleCaptures(b, pieces[i].second.first, pieces[i].second.second).size()); 
         newMove = pieces[i].first->getPossibleCaptures(b, pieces[i].second.first, pieces[i].second.second)[random]; 
         cout << "prioritized capture" << endl;
         cout << "Making capture " << "(" << pieces[i].second.first << ", " << pieces[i].second.second << ") -> (" << newMove.first << ", " << newMove.second << " )" << endl;
         cout << pieces[i].first->getType() << " captured " << b.getPiece(newMove.first, newMove.second)->getType() << endl;
         return Move{pieces[i].second.first, pieces[i].second.second, newMove.first, newMove.second, true, pieces[i].first}; 
      }
      for (size_t j = 0; j < pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second).size(); j++) {
         if (b.isMoveCheck(pieces[i].second.first, pieces[i].second.second, pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second)[j].first, pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second)[j].second)) {
            possibleChecks.push_back(Move{pieces[i].second.first, pieces[i].second.second, pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second)[j].first, pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second)[j].second, true, pieces[i].first} ); 
            cout << "Move puts game in check" << endl;
            //return Move{pieces[i].second.first, pieces[i].second.second, pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second)[j].first, pieces[i].first->getPossibleMoves(b, pieces[i].second.first, pieces[i].second.second)[j].second, true, pieces[i].first}; 
         }
      }
   }

    if (possibleChecks.size() != 0) {
        random = rand() % (possibleChecks.size()); 
        return possibleChecks[random]; 
    }

   //cout << "There are no possible captures" << endl;
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
    //cout << "Moving: " << b.getPiece(rstartX, rstartY)->getType() << endl;
    random = rand() % (moves.size()); 
    newMove = moves[random]; 

    return Move{rstartX, rstartY, newMove.first, newMove.second, b.getPiece(rstartX, rstartY)->isValidMove(b, rstartX, rstartY, newMove.first, newMove.second), b.getPiece(rstartX, rstartY)}; 
} 

