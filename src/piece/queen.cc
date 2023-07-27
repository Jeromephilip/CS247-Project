#include "queen.h"

Queen::Queen(string color): Piece{color} {
    if (color == "white") {
        this->type = 'Q';
    } else {
        this->type = 'q';
    }
}

vector<pair<int, int>> Queen::getPossibleMoves(Board& b, int x, int y) {
    Piece* getCurPiece = b.getPiece(x, y);
    vector<pair<int, int>> possibleMoves;

    if (!checkBounds(x, y, b)) {
        return possibleMoves; // return empty set
    }

    // northwest
    int tx = x - 1;
    int ty = y - 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == false) {
            possibleMoves.push_back({tx, ty});
        } else if(b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx--;
        ty--;
    }

    // southwest
    tx = x - 1;
    ty = y + 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == false) {
            possibleMoves.push_back({tx, ty});
        } else if(b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx--;
        ty++;
    }


    // southeast
    tx = x + 1;
    ty = y + 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == false) {
            possibleMoves.push_back({tx, ty});
        } else if(b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx++;
        ty++;
    }

    // northeast
    tx = x + 1;
    ty = y - 1;
    while (checkBounds(tx, ty, b)) {
        if (b.getSquare(tx, ty)->checkOccupied() == true && b.getSquare(tx, ty)->getPieceOnSquare()->getColor() == getCurPiece->getColor()) {
            break;
        } else if (b.getSquare(tx, ty)->checkOccupied() == false) {
            possibleMoves.push_back({tx, ty});
        } else if(b.getSquare(tx, ty)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(tx, ty)->getPieceOnSquare()->getType() != 'k')) {
            possibleMoves.push_back({tx, ty});
            break;
        }
        tx++;
        ty--;
    }

    // going north
    for (int i=y; i >= 0; i--) {
        // check if square is occupied with a piece of the same color (i != y so that it is not the current piece)
        if (b.getSquare(x, i)->checkOccupied() == true && b.getSquare(x, i)->getPieceOnSquare()->getColor() == getCurPiece->getColor() && i != y) {
            break;
        // open square
        } else if (b.getSquare(x, i)->checkOccupied() == false) {
            possibleMoves.push_back({x, i});
        // square with a piece that can be captured
        } else if (b.getSquare(x, i)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(x, i)->getPieceOnSquare()->getType()) != 'k') {
            possibleMoves.push_back({x, i});
            break;
        }
    }
    
    // going south
    for (int i=y; i < b.getHeight(); i++) {
        if (b.getSquare(x, i)->checkOccupied() == true && b.getSquare(x, i)->getPieceOnSquare()->getColor() == getCurPiece->getColor() && i != y) {
            break;
        } else if (b.getSquare(x, i)->checkOccupied() == false) {
            possibleMoves.push_back({x, i});
        } else if (b.getSquare(x, i)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(x, i)->getPieceOnSquare()->getType()) != 'k') {
            possibleMoves.push_back({x, i});
            break;
        }
    }
    
    // // going east
    for (int i=x; i < b.getWidth(); i++) {
        if (b.getSquare(i, y)->checkOccupied() == true && b.getSquare(i, y)->getPieceOnSquare()->getColor() == getCurPiece->getColor() && x != i) {
            break;
        } else if (b.getSquare(i, y)->checkOccupied() == false) {
            possibleMoves.push_back({i, y});
        } else if (b.getSquare(i, y)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(i, y)->getPieceOnSquare()->getType()) != 'k') {
            possibleMoves.push_back({i, y});
            break;
        }
    }

    // going west
    for (int i=x; i >= 0; i--) {
        if (b.getSquare(i, y)->checkOccupied() == true && b.getSquare(i, y)->getPieceOnSquare()->getColor() == getCurPiece->getColor() && x != i) {
            break;
        } else if (b.getSquare(i, y)->checkOccupied() == false) {
            possibleMoves.push_back({i, y});
        } else if (b.getSquare(i, y)->getPieceOnSquare()->getColor() != getCurPiece->getColor() && tolower(b.getSquare(i, y)->getPieceOnSquare()->getType()) != 'k') {
            possibleMoves.push_back({i, y});
            break;
        }
    }

    return possibleMoves;
}

bool Queen::isValidMove(Board& b, int curX, int curY, int newX, int newY) {
    vector<pair<int, int>> posMoves = getPossibleMoves(b, curX, curY);
    for (const auto& pair : posMoves) {
        if (pair.first == newX && pair.second == newY) {
            return true;
        }
    }
    return false;
}

Queen::~Queen() {}