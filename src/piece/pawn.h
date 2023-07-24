#ifndef PAWN_H
#define PAWN_H
#include <string>
#include <vector>
#include <utility>
#include "piece.h"

using namespace std;

class Pawn : public Piece {
    public:
        Pawn(string color);
        vector<pair<int, int>> getPossibleMoves(Piece* ,Board , int, int) override;
        bool isValidMove(int, int, int, int) override;
        ~Pawn();
};

#endif