#ifndef ROOK_H
#define ROOK_H
#include <string>
#include <vector>
#include <utility>
#include "piece.h"
#include <cctype>

using namespace std;

class Rook : public Piece {
    public:
        Rook(string );
        vector<pair<int, int>> getPossibleMoves(Board& , int, int) override;
        bool isValidMove(Board& , int, int, int, int) override;
        vector<pair<int, int>> getPossibleCaptures(Board& , int, int) override;
        ~Rook();
};

#endif
