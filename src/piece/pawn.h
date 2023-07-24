#ifndef PAWN_H
#define PAWN_H
#include <string>
#include <vector>
#include <utility>
#include "piece.h"

using namespace std;

class Pawn : public Piece {
    private:
        bool hasMoved = false;
    public:
        Pawn(string color);
        vector<pair<int, int>> getPossibleMoves(Board , int, int) override;
        bool isValidMove(Board b, int, int, int, int) override;
        ~Pawn();
};

#endif