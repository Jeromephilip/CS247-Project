#include "piece.h"

Piece::Piece(string color): color{color} {}

string Piece::getColor() {
    return color;
}

char Piece::getType() {
    return type;
}

Piece::~Piece() {}