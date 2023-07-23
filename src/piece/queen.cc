#include "queen.h"

Queen::Queen(string color): Piece{color} {
    if (color == "white") {
        this->type = 'Q';
    } else {
        this->type = 'q';
    }
}

vector<pair<int, int>> Queen::getPossibleMoves(Piece* p, Board b, int x, int y) {
    vector<pair<int, int>> temp = {{1,2}};
    return temp;
}

bool Queen::isValidMove(int curX, int curY, int newX, int newY) {
    return false;
}

Queen::~Queen() {}