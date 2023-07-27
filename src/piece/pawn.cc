#include "pawn.h"

Pawn::Pawn(string color): Piece{color} {
    if (color == "white") {
        this->type = 'P';
    } else {
        this->type = 'p';
    }
}

vector<pair<int, int>> Pawn::getPossibleCaptures(Board& b, int x, int y) {
    vector<pair<int, int>> possibleMoves;
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }
    if (this->color == "white") {
        if (checkBounds(x-1, y-1, b) && b.getSquare(x-1, y-1)->checkOccupied() == true && b.getSquare(x-1, y-1)->getPieceOnSquare()->getColor() == "black" && tolower(b.getPiece(x-1, y-1)->getType() != 'k')) {
            possibleMoves.push_back({x + 1, y + 1});
        }

        if (checkBounds(x-1, y-2, b) && b.getSquare(x-1, y-2)->checkOccupied() == true && b.getSquare(x-1, y-2)->getPieceOnSquare()->getColor() == "black" && tolower(b.getPiece(x-1, y-2)->getType() != 'k')) {
            possibleMoves.push_back({x - 1, y + 1});
        }
    } else {
        if (checkBounds(x+1, y+1, b) && b.getSquare(x+1, y+1)->checkOccupied() == true && b.getSquare(x+1, y+1)->getPieceOnSquare()->getColor() == "white" && tolower(b.getPiece(x+1, y+1)->getType() != 'k')) {
            possibleMoves.push_back({x + 1, y + 1});
        }

        if (checkBounds(x-1, y+1, b) && b.getSquare(x-1, y+1)->checkOccupied() == true && b.getSquare(x-1, y+1)->getPieceOnSquare()->getColor() == "white" && tolower(b.getPiece(x-1, y+1)->getType() != 'k')) {
            possibleMoves.push_back({x - 1, y + 1});
        }
    }
    return possibleMoves;
}

vector<pair<int, int>> Pawn::getPossibleMoves(Board& b, int x, int y) {
    vector<pair<int, int>> possibleMoves;
    if (!checkBounds(x, y, b) || b.getPiece(x, y) == nullptr) {
        return possibleMoves; // return empty set
    }
    // white color -> moves up the board. Y translation is negative
    if (this->color == "white") {
        // cout << "white" << endl;
        // move two spaces
        if (this->hasMoved == false) {
            if (checkBounds(x, y-2, b) && b.getSquare(x, y-2)->checkOccupied() == false) {
                possibleMoves.push_back({x, y-2});
            }
        }
        // move one space
        if (checkBounds(x, y-1, b) && b.getSquare(x, y-1)->checkOccupied() == false) {
            possibleMoves.push_back({x, y-1});
        }
        // captures
        if (checkBounds(x-1, y-1, b) && b.getSquare(x-1, y-1)->checkOccupied() == true && b.getSquare(x-1, y-1)->getPieceOnSquare()->getColor() == "black" && tolower(b.getPiece(x-1, y-1)->getType() != 'k')) {
            possibleMoves.push_back({x + 1, y + 1});
        }

        if (checkBounds(x-1, y-2, b) && b.getSquare(x-1, y-2)->checkOccupied() == true && b.getSquare(x-1, y-2)->getPieceOnSquare()->getColor() == "black" && tolower(b.getPiece(x-1, y-2)->getType() != 'k')) {
            possibleMoves.push_back({x - 1, y + 1});
        }

    // black color -> moves down the board. Y translation is positive. 
    } else {
        // move two spaces
        if (this->hasMoved == false) {
            if (checkBounds(x, y+2, b) && b.getSquare(x, y+2)->checkOccupied() == false) {
                // cout << "isoccupied" << endl;
                possibleMoves.push_back({x, y+2});
            }
        }
        // move one space
        if (checkBounds(x, y+1, b) && b.getSquare(x, y+1)->checkOccupied() == false) {
            possibleMoves.push_back({x, y+1});
        }
        
        // captures
        if (checkBounds(x+1, y+1, b) && b.getSquare(x+1, y+1)->checkOccupied() == true && b.getSquare(x+1, y+1)->getPieceOnSquare()->getColor() == "white" && tolower(b.getPiece(x+1, y+1)->getType() != 'k')) {
            possibleMoves.push_back({x + 1, y + 1});
        }

        if (checkBounds(x-1, y+1, b) && b.getSquare(x-1, y+1)->checkOccupied() == true && b.getSquare(x-1, y+1)->getPieceOnSquare()->getColor() == "white" && tolower(b.getPiece(x-1, y+1)->getType() != 'k')) {
            possibleMoves.push_back({x - 1, y + 1});
        }

    } 
    return possibleMoves;
}

bool Pawn::isValidMove(Board& b, int curX, int curY, int newX, int newY) {
    vector <pair<int, int>> possibleMoves = getPossibleMoves(b, curX, curY);
    for (const auto& pair : possibleMoves) {
        if (pair.first == newX && pair.second == newY) {
            return true;
        }
    }
    return false;
}

Pawn::~Pawn() {}