#ifndef KING_H
#define KING_H
#include "piece.h"
#include <string>
#include <vector>
#include <utility>

using namespace std;

class King : public Piece {
    private: 
        bool findInMoves(vector<pair<int,int>>, int, int);
    public:
        King(string );
        vector<pair<int, int>> getPossibleMoves(Board , int, int) override;
        bool isValidMove(Board b, int, int, int, int) override;
        bool checkCanCastle();
        vector<pair<int, int>> getCheckableSquares(Board, int, int);
        ~King();
};

#endif