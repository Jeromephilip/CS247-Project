#include "king.h"

King::King(string color): Piece{color} {
    if (color == "white") {
        this->type = 'K';
    } else {
        this->type = 'k';
    }
}

bool King::findInMoves(vector<pair<int,int>> v, int x, int y) {
    for (size_t i=0; i<v.size(); i++) {
        if (v[i].first == x && v[i].second == y) {
            return true;
        }
    }
    return false;
}

vector<pair<int, int>> King::getPossibleMoves(Board b, int x, int y) {
    // get all possible moves of opposite color
    // check if in this array
    // if not, add to possible moves.
    vector<pair<int, int>> possibleMoves;
    vector<pair<int, int>> checkableSquares = getCheckableSquares(b, x, y);
    // printMoves(checkableSquares);
    int incrPos = 1; 
    int incrNeg = -1;

   if (checkBounds(x + incrPos, y + incrPos, b)) {
        if (!(findInMoves(checkableSquares, x + incrPos, y + incrPos)) && b.getSquare(x + incrPos, y + incrPos)->checkOccupied() == false) {
            possibleMoves.push_back({x + incrPos, y + incrPos});
        }
    }

    if (checkBounds(x + incrPos, y, b)) {
        if (!(findInMoves(checkableSquares, x + incrPos, y)) && b.getSquare(x + incrPos, y)->checkOccupied() == false) {
            possibleMoves.push_back({x + incrPos, y});
        }
    }

    if (checkBounds(x, y + incrPos, b)) {
        if (!(findInMoves(checkableSquares, x, y + incrPos)) && b.getSquare(x, y + incrPos)->checkOccupied() == false) {
            possibleMoves.push_back({x, y + incrPos});
        }
    }
    if (checkBounds(x + incrNeg, y + incrNeg, b)) {
        if (!(findInMoves(checkableSquares, x + incrNeg, y + incrNeg)) && b.getSquare(x + incrNeg, y + incrNeg)->checkOccupied() == false) {
            possibleMoves.push_back({x + incrNeg, y + incrNeg});
        }
    }
    if (checkBounds(x, y + incrNeg, b)) {
        if (!(findInMoves(checkableSquares, x, y + incrNeg)) && b.getSquare(x, y + incrNeg)->checkOccupied() == false) {
            possibleMoves.push_back({x, y + incrNeg});
        }
    }
      
    if (checkBounds(x + incrNeg, y, b)) {
        if (!(findInMoves(checkableSquares, x + incrNeg, y)) && b.getSquare(x + incrNeg, y)->checkOccupied() == false) {
            possibleMoves.push_back({x + incrNeg, y});
        }
    }

    if (checkBounds(x + incrPos, y + incrNeg, b)) {
        if (!(findInMoves(checkableSquares, x + incrPos, y + incrNeg)) && b.getSquare(x + incrPos, y + incrNeg)->checkOccupied() == false) {
            possibleMoves.push_back({x + incrPos, y + incrNeg});
        }
    }
    
    if (checkBounds(x + incrNeg, y + incrPos, b)) {
        if (!(findInMoves(checkableSquares, x + incrNeg, y + incrPos)) && b.getSquare(x + incrNeg, y + incrPos)->checkOccupied() == false) {
            possibleMoves.push_back({x + incrNeg, y + incrPos});
        }
    } 


    printMoves(possibleMoves);

    return possibleMoves;
}

vector<pair<int, int>> King::getCheckableSquares(Board b, int x, int y) {
    Piece* getKingPiece = b.getPiece(x, y);
    vector<pair<int, int>> checkableSquares;

    for (int i=0; i<b.getHeight(); i++) {
        for (int j=0; j<b.getWidth(); j++) {
            if (b.getSquare(j, i)->checkOccupied() && b.getPiece(j, i)->getColor() != getKingPiece->getColor()) {
                vector<pair<int, int>> posMoves = b.getPiece(j, i)->getPossibleMoves(b, j, i);
                for (size_t k=0; k<posMoves.size(); k++) {
                    checkableSquares.push_back(posMoves[k]);
                }
            }
        }
    }

    return checkableSquares;
}

bool King::isValidMove(Board b, int curX, int curY, int newX, int newY) {
    vector<pair<int, int>> posMoves = getPossibleMoves(b, curX, curY);
    for (const auto& pair : posMoves) {
        if (pair.first == newX && pair.second == newY) {
            return true;
        }
    }
    return false;
}

bool King::checkCanCastle() {
    return !hasMoved;
}

King::~King() {}