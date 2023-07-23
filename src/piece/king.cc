#include "king.h"


King::King() {
    canCastle = true;
}

vector<pair<int, int>> King::getPossibleMoves(Piece* p, Board b, int x, int y) {
    vector<pair<int, int>> temp = {{1,2}};
    return temp;
}

bool King::isValidMove(int curX, int curY, int newX, int newY) {
    return false;
}

King::~King() {}