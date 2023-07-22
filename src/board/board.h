#include "../square/square.h"
#include "../piece/piece.h"
#include <vector>
#include <iostream>

using namespace std;


class Board {
    private:
        vector<vector<Square*>> board;
    public:
        Board();
        void getPiece(int, int);
        void movePiece(int, int, int, int);
        void removePiece(int, int, int, int);
        void printBoard();
};