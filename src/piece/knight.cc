#include "knight.h"

Knight::Knight(string color): Piece{color} {
    if (color == "white") {
        this->type = 'N';
    } else {
        this->type = 'n';
    }
}

vector<pair<int, int>> Knight::getPossibleMoves(Board b, int x, int y) {
    vector<pair<int, int>> temp = {{1,2}};
    return temp;
}

bool Knight::isValidMove(Board b, int curX, int curY, int newX, int newY) {
    return false;
}

Knight::~Knight() {}
