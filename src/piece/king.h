#ifndef KING_H
#define KING_H

#include "piece.h"

using namespace std;

class King : public Piece {
    private:
        bool canCastle;
    public:
        King();
        vector<pair<int, int>> getPossibleMoves(Piece* ,Board , int, int) override;
        bool isValidMove(int, int, int, int) override;
        bool checkCanCastle();
        ~King();
};

#endif