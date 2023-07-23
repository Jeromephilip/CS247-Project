#include "pawn.h"

Pawn::Pawn(string color): Piece{color} {
    if (color == "white") {
        this->type = 'P';
    } else {
        this->type = 'p';
    }
}

vector<pair<int, int>> Pawn::getPossibleMoves(Piece* p, Board b, int x, int y) {
    vector<pair<int, int>> temp = {{1,2}};
    return temp;
}

bool Pawn::isValidMove(int curX, int curY, int newX, int newY) {
    return false;
}

Pawn::~Pawn() {}