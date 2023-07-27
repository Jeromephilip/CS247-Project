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
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }

    Piece* getCurPiece = b.getPiece(x, y);

    vector<int> dx = {-1, -2, -2, -1, 1, 2, 2, 1};
    vector<int> dy = {-2, -1, 1, 2, 2, 1, -1, -2};

    for (int i=0; i<8; i++) {
        int tx = dx[i] + x;
        int ty = dy[i] + y;
        if (checkBounds(tx, ty, b)) {
            if (b.getSquare(tx, ty)->checkOccupied() == false || (b.getPiece(tx, ty)->getColor() != getCurPiece->getColor() && tolower(b.getPiece(tx, ty)->getType() != 'k'))) {
                possibleMoves.push_back({tx, ty});
            }
        }
    }
    return possibleMoves;
}

vector<pair<int, int>> Knight::getPossibleCaptures(Board& b, int x, int y) {
    vector<pair<int, int>> possibleMoves;
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }

    Piece* getCurPiece = b.getPiece(x, y);

    vector<int> dx = {-1, -2, -2, -1, 1, 2, 2, 1};
    vector<int> dy = {-2, -1, 1, 2, 2, 1, -1, -2};

    for (int i=0; i<8; i++) {
        int tx = dx[i] + x;
        int ty = dy[i] + y;
        if (checkBounds(tx, ty, b)) {
            if (b.getSquare(tx, ty)->checkOccupied() == true && b.getPiece(tx, ty)->getColor() != getCurPiece->getColor() && tolower(b.getPiece(tx, ty)->getType() != 'k')) {
                possibleMoves.push_back({tx, ty});
            }
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
