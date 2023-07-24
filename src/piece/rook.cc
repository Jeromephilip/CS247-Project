#include "rook.h"

Rook::Rook(string color): Piece{color} {
    if (color == "white") {
        this->type = 'R';
    } else {
        this->type = 'r';
    }
}

vector<pair<int, int>> Rook::getPossibleMoves(Board b, int x, int y) {
    Piece* getCurPiece = b.getPiece(x, y);
    vector<pair<int, int>> possibleMoves;

    if (checkBounds(x, y, b)) {
        return possibleMoves; // return empty set
    }
    // going up
    for (int i=y; i >= 0; i--) {
        if (b.getSquare(x, i)->checkOccupied() == false || b.getSquare(x, i)->getPieceOnSquare()->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({x, i});
        }
    }
    // going down
    for (int i=y; i < b.getHeight(); i++) {
        if (b.getSquare(x, i)->checkOccupied() == false || b.getSquare(x, i)->getPieceOnSquare()->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({x, i});
        }
    }
    // going right
    for (int i=x; x < b.getWidth(); i++) {
        if (b.getSquare(i, y)->checkOccupied() == false || b.getSquare(i, y)->getPieceOnSquare()->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({i, y});
        }
    }
    // going left
    for (int i=x; i >= 0; i--) {
        if (b.getSquare(i, y)->checkOccupied() == false || b.getSquare(i, y)->getPieceOnSquare()->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({i, y});
        }
    }
    return possibleMoves;
}

bool Rook::isValidMove(Board b, int curX, int curY, int newX, int newY) {
    return false;
}

Rook::~Rook() {}