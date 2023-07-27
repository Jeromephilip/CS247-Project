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
        bool checkBounds(int, int, Board&);
        void printMoves(vector<pair<int, int>>); // for testing
        bool hasMoved = false;
    public:
        Piece(string );
        virtual vector<pair<int, int>> getPossibleMoves(Board& , int, int) = 0;
        virtual bool isValidMove(Board& , int, int, int, int) = 0; // check in getPossibleMoves if valid
        virtual vector<pair<int, int>> getPossibleCaptures(Board& , int, int) = 0;
        char getType();
        string getColor();
        bool getHasMoved();
        void setHasMoved(bool);
        virtual ~Piece();
};


#endif