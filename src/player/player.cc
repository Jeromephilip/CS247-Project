#include "player.h"

Player::Player(string colour, bool isComputer) : colour{colour}, isComputer{isComputer} {}

Player::~Player() {}

string Player::getColour() {
    return colour; 
}

bool Player::getBool() {
    return isComputer; 
}

vector<pair<Piece*, pair<int, int>>> Player::getPieces(Board& b) {
    pair<int, int> coordinates; 
    pair<Piece*, pair<int, int>> piece; 
    vector<pair<Piece*, pair<int, int>>> allPieces; 

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (b.getPiece(x, y) != nullptr && b.getPiece(x, y)->getColor() == colour) {
                coordinates.first = x; 
                coordinates.second = y; 

                piece.first = b.getPiece(x, y); 
                piece.second = coordinates; 

                allPieces.push_back(piece); 
            }
        }
    }
    // traverse the board
    // if b.getPiece(int x, int y) != nullptr && b.getPiece(int x, int y)->getColor() == colour 
        // then set coordinates to coordinates.first = x, coordinates.second = y
        // then piece.first == b.getPiece(int x, int y) and piece.second = coordinates
        // then allPieces.push_back(piece)
    // outside for loop, return allPieces 
    return allPieces; 
}

bool Player::kingChecks(Board& b, int x, int y) {
    // if piece at int x, int y is not a king
    if (tolower(b.getSquare(x, y)->getPieceOnSquare()->getType()) != 'k') {
        if (b.checkBounds(x, y+1)) {
            if (b.getSquare(x, y+1)->checkOccupied() == true && b.getPiece(x, y+1)->getColor() != b.getSquare(x, y)->getColor() && (tolower(b.getPiece(x, y+1)->getType()) == 'k')) {
                for (size_t i = 0; i < b.getSquare(x, y+1)->getPieceOnSquare()->getPossibleCaptures(b, x, y+1).size(); i++) {
                    if (b.getSquare(x, y+1)->getPieceOnSquare()->getPossibleCaptures(b, x, y+1)[i].first == x && b.getSquare(x, y+1)->getPieceOnSquare()->getPossibleCaptures(b, x, y+1)[i].second == y) {
                        // then this is a valid move 
                        // this means that a king puts this piece, that is not a king, in check by a king 
                        return true; 
                    }
                }
                
            }
        }
        if (b.checkBounds(x, y-1)) {
            if (b.getSquare(x, y-1)->checkOccupied() == true && b.getPiece(x, y-1)->getColor() != b.getSquare(x, y)->getColor() && (tolower(b.getPiece(x, y-1)->getType()) == 'k')) {
                for (size_t i = 0; i < b.getSquare(x, y-1)->getPieceOnSquare()->getPossibleCaptures(b, x, y-1).size(); i++) {
                    if (b.getSquare(x, y-1)->getPieceOnSquare()->getPossibleCaptures(b, x, y-1)[i].first == x && b.getSquare(x, y-1)->getPieceOnSquare()->getPossibleCaptures(b, x, y-1)[i].second == y) {
                        // then this is a valid move 
                        // this means that a king puts this piece, that is not a king, in check by a king 
                        return true; 
                    }
                }
                
            }
        }
        if (b.checkBounds(x+1, y)) {
            if (b.getSquare(x+1, y)->checkOccupied() == true && b.getPiece(x+1, y)->getColor() != b.getSquare(x, y)->getColor() && (tolower(b.getPiece(x+1, y)->getType()) == 'k')) {
                for (size_t i = 0; i < b.getSquare(x+1, y)->getPieceOnSquare()->getPossibleCaptures(b, x+1, y).size(); i++) {
                    if (b.getSquare(x+1, y)->getPieceOnSquare()->getPossibleCaptures(b, x+1, y)[i].first == x && b.getSquare(x+1, y)->getPieceOnSquare()->getPossibleCaptures(b, x+1, y)[i].second == y) {
                        // then this is a valid move 
                        // this means that a king puts this piece, that is not a king, in check by a king 
                        return true; 
                    }
                }
                
            }
        }
        if (b.checkBounds(x+1, y+1)) {
            if (b.getSquare(x+1, y+1)->checkOccupied() == true && b.getPiece(x+1, y+1)->getColor() != b.getSquare(x, y+1)->getColor() && (tolower(b.getPiece(x+1, y+1)->getType()) == 'k')) {
                for (size_t i = 0; i < b.getSquare(x+1, y+1)->getPieceOnSquare()->getPossibleCaptures(b, x+1, y+1).size(); i++) {
                    if (b.getSquare(x+1, y+1)->getPieceOnSquare()->getPossibleCaptures(b, x+1, y+1)[i].first == x && b.getSquare(x+1, y+1)->getPieceOnSquare()->getPossibleCaptures(b, x+1, y+1)[i].second == y) {
                        // then this is a valid move 
                        // this means that a king puts this piece, that is not a king, in check by a king 
                        return true; 
                    }
                }
                
            }
        }
        if (b.checkBounds(x+1, y-1)) {
            if (b.getSquare(x+1, y-1)->checkOccupied() == true && b.getPiece(x+1, y-1)->getColor() != b.getSquare(x, y-1)->getColor() && (tolower(b.getPiece(x+1, y-1)->getType()) == 'k')) {
                for (size_t i = 0; i < b.getSquare(x+1, y-1)->getPieceOnSquare()->getPossibleCaptures(b, x+1, y-1).size(); i++) {
                    if (b.getSquare(x+1, y-1)->getPieceOnSquare()->getPossibleCaptures(b, x+1, y-1)[i].first == x && b.getSquare(x+1, y-1)->getPieceOnSquare()->getPossibleCaptures(b, x+1, y-1)[i].second == y) {
                        // then this is a valid move 
                        // this means that a king puts this piece, that is not a king, in check by a king 
                        return true; 
                    }
                }
                
            }
        }
        if (b.checkBounds(x-1, y)) {
            if (b.getSquare(x-1, y)->checkOccupied() == true && b.getPiece(x-1, y)->getColor() != b.getSquare(x, y)->getColor() && (tolower(b.getPiece(x-1, y)->getType()) == 'k')) {
                for (size_t i = 0; i < b.getSquare(x-1, y)->getPieceOnSquare()->getPossibleCaptures(b, x-1, y).size(); i++) {
                    if (b.getSquare(x-1, y)->getPieceOnSquare()->getPossibleCaptures(b, x-1, y)[i].first == x && b.getSquare(x-1, y)->getPieceOnSquare()->getPossibleCaptures(b, x-1, y)[i].second == y) {
                        // then this is a valid move 
                        // this means that a king puts this piece, that is not a king, in check by a king 
                        return true; 
                    }
                }
                
            }
        }
        if (b.checkBounds(x-1, y+1)) {
            if (b.getSquare(x-1, y+1)->checkOccupied() == true && b.getPiece(x-1, y+1)->getColor() != b.getSquare(x, y)->getColor() && (tolower(b.getPiece(x-1, y+1)->getType()) == 'k')) {
                for (size_t i = 0; i < b.getSquare(x-1, y+1)->getPieceOnSquare()->getPossibleCaptures(b, x-1, y+1).size(); i++) {
                    if (b.getSquare(x-1, y+1)->getPieceOnSquare()->getPossibleCaptures(b, x-1, y+1)[i].first == x && b.getSquare(x-1, y+1)->getPieceOnSquare()->getPossibleCaptures(b, x-1, y+1)[i].second == y) {
                        // then this is a valid move 
                        // this means that a king puts this piece, that is not a king, in check by a king 
                        return true; 
                    }
                }
                
            }
        }
        if (b.checkBounds(x-1, y-1)) {
            if (b.getSquare(x-1, y-1)->checkOccupied() == true && b.getPiece(x-1, y-1)->getColor() != b.getSquare(x, y)->getColor() && (tolower(b.getPiece(x-1, y-1)->getType()) == 'k')) {
                for (size_t i = 0; i < b.getSquare(x-1, y-1)->getPieceOnSquare()->getPossibleCaptures(b, x-1, y-1).size(); i++) {
                    if (b.getSquare(x-1, y-1)->getPieceOnSquare()->getPossibleCaptures(b, x-1, y-1)[i].first == x && b.getSquare(x-1, y-1)->getPieceOnSquare()->getPossibleCaptures(b, x-1, y-1)[i].second == y) {
                        // then this is a valid move 
                        // this means that a king puts this piece, that is not a king, in check by a king 
                        return true; 
                    }
                }
                
            }
        }
    }
    return false; 
}
