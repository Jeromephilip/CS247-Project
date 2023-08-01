#include "square.h"

Square::Square(string color, int x, int y): p{nullptr}, x{x}, y{y}, color{color}, isOccupied{false} {}

Piece* Square::getPieceOnSquare() {
    return this->p;
}

bool Square::checkOccupied() {
    return isOccupied;
}

void Square::setPieceOnSquare(Piece* pieceToSet) {
    this->p = pieceToSet;
    this->isOccupied = true;
}

void Square::removePieceOnSquare() {
    this->p = nullptr;
    this->isOccupied = false;
}

void Square::capturePieceOnSquare() {
    delete this->p;
    this->p = nullptr;
    this->isOccupied = false;
}

int Square::getX() {
    return x;
}

int Square::getY() {
    return y;
}

string Square::getColor() {
    return color;
}

Square::~Square() {
    delete p;
}
