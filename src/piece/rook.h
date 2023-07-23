#ifndef ROOK_H
#define ROOK_H
#include <string>
#include <vector>
#include <utility>
#include "piece.h"

using namespace std;

class Rook : public Piece {
    public:
        Rook(string );
        vector<pair<int, int>> getPossibleMoves(Piece* ,Board , int, int) override;
        bool isValidMove(int, int, int, int) override;
        ~Rook();
};

#endif