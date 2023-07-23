#ifndef QUEEN_H
#define QUEEN_H
#include <string>
#include <vector>
#include <utility>
#include "piece.h"

class Queen : public Piece {
    public:
        Queen(string );
        vector<pair<int, int>> getPossibleMoves(Piece* ,Board , int, int) override;
        bool isValidMove(int, int, int, int) override;
        ~Queen();
};

#endif