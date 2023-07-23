#include "pawn.h"

Pawn::Pawn(string color): Piece{color}, hasMoved{false} {
    if (color == "white") {
        this->type = 'P';
    } else {
        this->type = 'p';
    }
}

vector<pair<int, int>> Pawn::getPossibleMoves(Piece* p, Board b, int x, int y) {
    vector<pair<int, int>> possibleMoves;
    if (color == "white") {
        possibleMoves.push_back({x, y-1});
    } else {
        possibleMoves.push_back({x, y+1});
    }
    return possibleMoves;
}

bool Pawn::isValidMove(int curX, int curY, int newX, int newY) {
    return false;
}

Pawn::~Pawn() {}