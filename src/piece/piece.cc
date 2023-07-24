#include "piece.h"

Piece::Piece(string color): color{color} {}

string Piece::getColor() {
    return color;
}

char Piece::getType() {
    return type;
}

bool Piece::checkBounds(int x, int y, Board b) {
    if ((0 <= x && x < b.getWidth()) && (0 <= y && y < b.getHeight())) {
        return true;
    }
    return false;
}

bool Piece::getHasMoved() {
    return hasMoved;
}

void Piece::setHasMoved(bool b) {
    this->hasMoved = b;
}

Piece::~Piece() {}