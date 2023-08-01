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
        vector<pair<int, int>> getPossibleMoves(Board& , int, int) override;
        vector<pair<int, int>> getPossibleCaptures(Board& , int, int) override;
        bool isValidMove(Board& , int, int, int, int) override;
        ~Knight();
};

#endif
