#include "knight.h"

Knight::Knight(string color): Piece{color} {
    if (color == "white") {
        this->type = 'N';
    } else {
        this->type = 'n';
    }
}

vector<pair<int, int>> Knight::getPossibleMoves(Board& b, int x, int y) {
    vector<pair<int, int>> possibleMoves;
    Piece* getCurPiece = b.getPiece(x, y);

    int tx = x + 2;
    int ty = y + 1;
    if (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == false || b.getPiece(tx, ty)->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({tx, ty});
        }
    }
    
    tx = x + 2;
    ty = y - 1;
    if (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == false || b.getPiece(tx, ty)->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({tx, ty});
        }
    }

    tx = x + 1;
    ty = y - 2;
    if (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == false || b.getPiece(tx, ty)->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({tx, ty});
        }
    }

    tx = x + 1;
    ty = y + 2;
    if (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == false || b.getPiece(tx, ty)->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({tx, ty});
        }
    }

    tx = x - 1;
    ty = y - 2;
    if (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == false || b.getPiece(tx, ty)->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({tx, ty});
        }
    }

    tx = x - 2;
    ty = y - 1;
    if (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == false || b.getPiece(tx, ty)->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({tx, ty});
        }
    }

    tx = x - 2;
    ty = y + 1;
    if (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == false || b.getPiece(tx, ty)->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({tx, ty});
        }
    }

    tx = x - 1;
    ty = y + 2;
    if (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == false || b.getPiece(tx, ty)->getColor() != getCurPiece->getColor()) {
            possibleMoves.push_back({tx, ty});
        }
    }

    return possibleMoves;
}

bool Knight::isValidMove(Board& b, int curX, int curY, int newX, int newY) {
    vector<pair<int, int>> posMoves = getPossibleMoves(b, curX, curY);
    for (const auto& pair : posMoves) {
        if (pair.first == newX && pair.second == newY) {
            return true;
        }
    }
    return false;
}

Knight::~Knight() {}
