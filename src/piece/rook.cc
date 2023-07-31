#include "rook.h"

Rook::Rook(string color): Piece{color} {
    if (color == "white") {
        this->type = 'R';
    } else {
        this->type = 'r';
    }
}

vector<pair<int, int>> Rook::getPossibleMoves(Board& b, int x, int y) {
    // cout << "Rook's Possible Moves" << endl;
    vector<pair<int, int>> possibleMoves;
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }

    
    Piece* getCurPiece = b.getPiece(x, y);
    // cout << b.getWidth() << endl;
    // already checks bounds in the loop
    // going up
    if (checkBounds(x, y-1, b)) {
        for (int i=y-1; i >= 0; i--) {
            // check if square is occupied with a piece of the same color (i != y so that it is not the current piece)
            if (b.getSquare(x, i)->checkOccupied() == true && b.getSquare(x, i)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
                break;
            // open square
            } else if (b.getSquare(x, i)->checkOccupied() == false) {
                possibleMoves.push_back({x, i});
            // square with a piece that can be captured
            } else if (b.getSquare(x, i)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(x, i)->getPieceOnSquare()->getType()) != 'k') {
                possibleMoves.push_back({x, i});
                break;
            }
        }
    }
    
    if (checkBounds(x, y+1, b)) {
        for (int i=y+1; i < b.getHeight(); i++) {
            if (b.getSquare(x, i)->checkOccupied() == true && b.getSquare(x, i)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
                break;
            } else if (b.getSquare(x, i)->checkOccupied() == false) {
                possibleMoves.push_back({x, i});
            } else if (b.getSquare(x, i)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(x, i)->getPieceOnSquare()->getType()) != 'k') {
                possibleMoves.push_back({x, i});
                break;
            }
        }
    }
    // going down

    // // going right
    if (checkBounds(x+1, y, b)) {
        for (int i=x+1; i < b.getWidth(); i++) {
            if (b.getSquare(i, y)->checkOccupied() == true && b.getSquare(i, y)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
                break;
            } else if (b.getSquare(i, y)->checkOccupied() == false) {
                possibleMoves.push_back({i, y});
            } else if (b.getSquare(i, y)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(i, y)->getPieceOnSquare()->getType()) != 'k') {
                possibleMoves.push_back({i, y});
                break;
            }
        }
    }

    // // going left
    if (checkBounds(x-1, y, b)) {
        for (int i=x-1; i >= 0; i--) {
            if (b.getSquare(i, y)->checkOccupied() == true && b.getSquare(i, y)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
                break;
            } else if (b.getSquare(i, y)->checkOccupied() == false) {
                possibleMoves.push_back({i, y});
            } else if (b.getSquare(i, y)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(i, y)->getPieceOnSquare()->getType()) != 'k') {
                possibleMoves.push_back({i, y});
                break;
            }
        }
    }


    vector<pair<int, int>> filteredPossibleMoves; 
    for (size_t i=0; i<possibleMoves.size(); i++) {
        if (b.isMoveAllowed(x, y, possibleMoves[i].first, possibleMoves[i].second)) {
            filteredPossibleMoves.push_back(possibleMoves[i]);
        }
    }

    // printMoves(filteredPossibleMoves);
    return filteredPossibleMoves;
    // return possibleMoves;
}

vector<pair<int, int>> Rook::getPossibleCaptures(Board& b, int x, int y) {
    vector<pair<int, int>> possibleMoves;
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }
    Piece* getCurPiece = b.getPiece(x, y);
    // cout << b.getWidth() << endl;
    // already checks bounds in the loop
    // going up
    for (int i=y; i >= 0; i--) {
        // check if square is occupied with a piece of the same color (i != y so that it is not the current piece)
        if (b.getSquare(x, i)->checkOccupied() == true && b.getSquare(x, i)->getPieceOnSquare()->getColor() == getCurPiece->getColor() && i != y) {
            break;
        // square with a piece that can be captured
        } else if (b.getSquare(x, i)->checkOccupied() == true && b.getSquare(x, i)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(x, i)->getPieceOnSquare()->getType()) != 'k') {
            possibleMoves.push_back({x, i});
            break;
        }
    }
    
    // going down
    for (int i=y; i < b.getHeight(); i++) {
        if (b.getSquare(x, i)->checkOccupied() == true && b.getSquare(x, i)->getPieceOnSquare()->getColor() == getCurPiece->getColor() && i != y) {
            break;
        } else if (b.getSquare(x, i)->checkOccupied() == true && b.getSquare(x, i)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(x, i)->getPieceOnSquare()->getType()) != 'k') {
            possibleMoves.push_back({x, i});
            break;
        }
    }
    // // going right
    for (int i=x; i < b.getWidth(); i++) {
        if (b.getSquare(i, y)->checkOccupied() == true && b.getSquare(i, y)->getPieceOnSquare()->getColor() == getCurPiece->getColor() && x != i) {
            break;
        } else if (b.getSquare(i, y)->checkOccupied() == true && b.getSquare(i, y)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(i, y)->getPieceOnSquare()->getType()) != 'k') {
            possibleMoves.push_back({i, y});
            break;
        }
    }
    // // going left
    for (int i=x; i >= 0; i--) {
        if (b.getSquare(i, y)->checkOccupied() == true && b.getSquare(i, y)->getPieceOnSquare()->getColor() == getCurPiece->getColor() && x != i) {
            break;
        } else if (b.getSquare(i, y)->checkOccupied() == true && b.getSquare(i, y)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(i, y)->getPieceOnSquare()->getType()) != 'k') {
            possibleMoves.push_back({i, y});
            break;
        }
    }
    return possibleMoves;
}

bool Rook::isValidMove(Board& b, int curX, int curY, int newX, int newY) {
    vector<pair<int, int>> posMoves = getPossibleMoves(b, curX, curY);
    for (const auto& pair : posMoves) {
        if (pair.first == newX && pair.second == newY) {
            return true;
        }
    }
    return false;
}

Rook::~Rook() {}