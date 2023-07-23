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
        vector<pair<int, int>> getPossibleMoves(Piece* ,Board , int, int) override;
        bool isValidMove(int, int, int, int) override;
        bool checkCanCastle();
        ~Bishop();
};

#endif