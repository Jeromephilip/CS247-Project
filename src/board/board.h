#ifndef BOARD_H
#define BOARD_H

#include "../square/square.h"
#include "../piece/piece.h"
#include <vector>
#include <iostream>

using namespace std;

class Piece;
class Square;
class Rook;

class Board {
    private:
        int height;
        int width;
        vector<vector<Square*>> board;
        bool checkBounds(int, int);
    public:
        Board(int, int);
        Piece* getPiece(int, int);
        void setPiece(Piece*, int, int);
        void movePiece(int, int, int, int);
        bool isCheck(string, int, int);
        bool isMoveCheck(int, int, int, int); 
        pair<int, int> findKing(string);
        void removePiece(int, int);
        void printBoard();
        int getWidth();
        int getHeight();
        void reset();
        bool isMoveAllowed(int, int, int, int);
        void swapPiece(int, int, int, int);
        void removePieceSetup(int, int);
        Square* getSquare(int, int);
        bool checkAdjacentKings(int, int);
        ~Board();
};

#endif