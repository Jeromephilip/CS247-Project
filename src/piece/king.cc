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

vector<pair<int, int>> King::getPossibleMoves(Board& b, int x, int y) {
    // get all possible moves of opposite color
    // check if in this array
    // if not, add to possible moves.

    vector<pair<int, int>> possibleMoves;
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }
    Piece *getCurPiece = b.getPiece(x, y);
    vector<pair<int, int>> checkableSquares = getCheckableSquares(b, x, y);
    // printMoves(checkableSquares);

    vector<int> dx = {1, 1, 1, -1, -1, -1, 0, 0};
    vector<int> dy = {1, -1, 0, 1, -1, 0, 1, -1};

    for (int i=0; i<8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (checkBounds(tx, ty, b)) {
            if (!(findInMoves(checkableSquares, tx, ty)) && b.getSquare(tx, ty)->checkOccupied() == false) {
                possibleMoves.push_back({tx, ty});
            } else if (b.getSquare(tx, ty)->checkOccupied() == true && b.getPiece(tx, ty)->getColor() != getCurPiece->getColor() && tolower(b.getPiece(tx, ty)->getType()) != 'k') {
                if (!b.isCheck(getCurPiece->getColor(), tx, ty) && b.checkAdjacentKings(tx, ty)) {
                    possibleMoves.push_back({tx, ty});
                }
            };
        }
    }

    // printMoves(possibleMoves);
    return possibleMoves;
}


vector<pair<int, int>> King::getPossibleCaptures(Board& b, int x, int y) {
    // --------TODO--------

    vector<pair<int, int>> possibleMoves;
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }
    Piece *getCurPiece = b.getPiece(x, y);
    //vector<pair<int, int>> checkableSquares = getCheckableSquares(b, x, y);
    // printMoves(checkableSquares);

    vector<int> dx = {1, 1, 1, -1, -1, -1, 0, 0};
    vector<int> dy = {1, -1, 0, 1, -1, 0, 1, -1};

    for (int i=0; i<8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (checkBounds(tx, ty, b)) {
            if (b.getSquare(tx, ty)->checkOccupied() == true && b.getPiece(tx, ty)->getColor() != getCurPiece->getColor() && tolower(b.getPiece(tx, ty)->getType()) != 'k') {
                if (!b.isCheck(getCurPiece->getColor(), tx, ty) && b.checkAdjacentKings(tx, ty)) {
                    possibleMoves.push_back({tx, ty});
                }
            };
        }
    }

    return possibleMoves;
}

vector<pair<int, int>> King::getCheckableSquares(Board& b, int x, int y) {
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

Piece* King::clone() const {
    return new King(*this);
}

bool King::isValidMove(Board& b, int curX, int curY, int newX, int newY) {
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