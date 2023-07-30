#include "bishop.h"

Bishop::Bishop(string color): Piece{color} {
    if (color == "white") {
        this->type = 'B';
    } else {
        this->type = 'b';
    }
}

vector<pair<int, int>> Bishop::getPossibleCaptures(Board& b, int x, int y) {
    vector<pair<int, int>> possibleMoves;
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }

    Piece* getCurPiece = b.getPiece(x, y);
    int tx = x - 1;
    int ty = y - 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if(b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx--;
        ty--;
    }

    // southwest
    tx = x - 1;
    ty = y + 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx--;
        ty++;
    }


    // southeast
    tx = x + 1;
    ty = y + 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx++;
        ty++;
    }

    // northeast
    tx = x + 1;
    ty = y - 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx++;
        ty--;
    }
    return possibleMoves;
}

vector<pair<int, int>> Bishop::getPossibleMoves(Board& b, int x, int y) {
    vector<pair<int, int>> possibleMoves;
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }
    Piece* getCurPiece = b.getPiece(x, y);
    // northwest
    int tx = x - 1;
    int ty = y - 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == false) {
            possibleMoves.push_back({tx, ty});
        } else if(b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx--;
        ty--;
    }

    // southwest
    tx = x - 1;
    ty = y + 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == false) {
            possibleMoves.push_back({tx, ty});
        } else if(b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx--;
        ty++;
    }


    // southeast
    tx = x + 1;
    ty = y + 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == false) {
            possibleMoves.push_back({tx, ty});
        } else if(b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx++;
        ty++;
    }

    // northeast
    tx = x + 1;
    ty = y - 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == false) {
            possibleMoves.push_back({tx, ty});
        } else if(b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx++;
        ty--;
    }


    vector<pair<int, int>> filteredPossibleMoves; 
    for (size_t i=0; i<possibleMoves.size(); i++) {
        if (b.isMoveAllowed(x, y, possibleMoves[i].first, possibleMoves[i].second)) {
            filteredPossibleMoves.push_back(possibleMoves[i]);
        }
    }

    printMoves(filteredPossibleMoves);
    return filteredPossibleMoves;
}


bool Bishop::isValidMove(Board& b, int curX, int curY, int newX, int newY) {
    vector<pair<int, int>> posMoves = getPossibleMoves(b, curX, curY);
    for (const auto& pair : posMoves) {
        if (pair.first == newX && pair.second == newY) {
            return true;
        }
    }
    return false;
}

Piece* Bishop::clone() const {
    return new Bishop(*this);
}

Bishop::~Bishop() {}