#ifndef QUEEN_H
#define QUEEN_H
#include <string>
#include <vector>
#include <utility>
#include "piece.h"

class Queen : public Piece {
    public:
        Queen(string );
        vector<pair<int, int>> getPossibleMoves(Board& , int, int) override;
        vector<pair<int, int>> getPossibleCaptures(Board&, int, int) override;
        bool isValidMove(Board& , int, int, int, int) override;
        virtual Piece* clone() const override;
        ~Queen();
};

#endif