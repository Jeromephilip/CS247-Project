#include "square.h"

Square::Square(string color, int x, int y): p{nullptr}, x{x}, y{y}, color{color}, isOccupied{false} {}

Square::Square(const Square& other) : p{nullptr}, x{other.x}, y{other.y}, color{other.color}, isOccupied{other.isOccupied} {
    if (other.p != nullptr) { 
        p = other.p->clone();
    }
}

Piece* Square::getPieceOnSquare() {
    return this->p;
}

bool Square::checkOccupied() {
    return isOccupied;
}

void Square::setPieceOnSquare(Piece* p) {
    this->p = p;
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