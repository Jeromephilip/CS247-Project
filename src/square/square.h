#ifndef SQUARE_H
#define SQUARE_H


#include "../piece/piece.h"
#include <string>
#include <iostream>

using namespace std;

class Piece;

class Square {
    private:
        Piece* p;
        int x, y;
        string color;
        bool isOccupied;
    public:
        Square(string, int, int);
        Piece* getPieceOnSquare();
        bool checkOccupied();
        void setPieceOnSquare(Piece*);
        void removePieceOnSquare();
        int getX();
        int getY();
        string getColor();
};

#endif