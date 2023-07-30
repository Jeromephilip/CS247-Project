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
