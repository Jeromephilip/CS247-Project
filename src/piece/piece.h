#include <string>
#include <vector>
#include <utility>
#include "../board/board.h"

using namespace std;

class Piece {
    private:
        string color;
        string type;
    public:
        virtual vector<pair<int, int>> getPossibleMoves(Piece , Board, int, int) = 0;
        virtual bool isValidMove(int, int, int, int) = 0; // check in getPossibleMoves if valid
}