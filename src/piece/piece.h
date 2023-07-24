#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <vector>
#include <utility>
#include "../board/board.h"

using namespace std;

class Board;

class Piece {
    protected:
        string color;
        char type;
        bool checkBounds(int, int, Board);
        bool hasMoved = false;
    public:
        Piece(string );
        virtual vector<pair<int, int>> getPossibleMoves(Board , int, int) = 0;
        virtual bool isValidMove(Board b, int, int, int, int) = 0; // check in getPossibleMoves if valid
        char getType();
        string getColor();
        bool getHasMoved();
        void setHasMoved(bool);
        virtual ~Piece();
};


#endif