#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Bishop : public Piece {
    public:
        Bishop(string color);
        vector<pair<int, int>> getPossibleMoves(Board& , int, int) override;
        bool isValidMove(Board&, int, int, int, int) override;
        vector<pair<int, int>> getPossibleCaptures(Board& , int, int) override;
        ~Bishop();
};

#endif