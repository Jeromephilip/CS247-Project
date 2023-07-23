#include "bishop.h"

Bishop::Bishop(string color): Piece{color} {
    if (color == "white") {
        this->type = 'B';
    } else {
        this->type = 'b';
    }
}

vector<pair<int, int>> Bishop::getPossibleMoves(Piece* p, Board b, int x, int y) {
    vector<pair<int, int>> temp = {{1,2}};
    return temp;
}

bool Bishop::isValidMove(int curX, int curY, int newX, int newY) {
    return false;
}

Bishop::~Bishop() {}