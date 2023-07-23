#ifndef KNIGHT_H
#define KNIGHT_H
#include <string>
#include <vector>
#include <utility>
#include "piece.h"

using namespace std;

class Knight : public Piece {
    public:
        Knight(string );
        vector<pair<int, int>> getPossibleMoves(Piece* ,Board , int, int) override;
        bool isValidMove(int, int, int, int) override;
        ~Knight();
};

#endif