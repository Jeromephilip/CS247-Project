#ifndef BOARD_H
#define BOARD_H

#include "../square/square.h"
#include "../piece/piece.h"
#include <vector>
#include <iostream>

using namespace std;

class Piece;
class Square;

class Board {
    private:
        vector<vector<Square*>> board;
        int width;
        int height;
    public:
        Board(int, int);
        Piece* getPiece(int, int);
        void setPiece(Piece*, int, int);
        void movePiece(int, int, int, int);
        void removePiece(int, int);
        void printBoard();
};

#endif