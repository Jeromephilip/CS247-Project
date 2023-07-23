#include "rook.h"

Rook::Rook(string color): Piece{color} {
    if (color == "white") {
        this->type = 'R';
    } else {
        this->type = 'r';
    }
}

vector<pair<int, int>> Rook::getPossibleMoves(Piece* p, Board b, int x, int y) {
    vector<pair<int, int>> temp = {{1,2}};
    return temp;
}

bool Rook::isValidMove(int curX, int curY, int newX, int newY) {
    return false;
}

Rook::~Rook() {}