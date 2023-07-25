#include "bishop.h"

Bishop::Bishop(string color): Piece{color} {
    if (color == "white") {
        this->type = 'B';
    } else {
        this->type = 'b';
    }
}

vector<pair<int, int>> Bishop::getPossibleMoves(Board b, int x, int y) {
    Piece* getCurPiece = b.getPiece(x, y);
    vector<pair<int, int>> possibleMoves;

    if (!checkBounds(x, y, b)) {
        return possibleMoves; // return empty set
    }

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


    return possibleMoves;
}

bool Bishop::isValidMove(Board b, int curX, int curY, int newX, int newY) {
    vector<pair<int, int>> posMoves = getPossibleMoves(b, curX, curY);
    for (const auto& pair : posMoves) {
        if (pair.first == newX && pair.second == newY) {
            return true;
        }
    }
    return false;
}

Bishop::~Bishop() {}