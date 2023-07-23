#include "king.h"

King::King(string color): Piece{color}, canCastle{true} {
    if (color == "white") {
        this->type = 'K';
    } else {
        this->type = 'k';
    }
}

vector<pair<int, int>> King::getPossibleMoves(Piece* p, Board b, int x, int y) {
    vector<pair<int, int>> temp = {{1,2}};
    return temp;
}

bool King::isValidMove(int curX, int curY, int newX, int newY) {
    return false;
}

bool King::checkCanCastle() {
    return canCastle;
}

King::~King() {}