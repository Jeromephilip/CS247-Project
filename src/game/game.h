#include "../board/board.h"
#include "../player/player.h"

using namespace std;

class Game {
    private:
        Board b;
        bool isCheck = false;
        bool isCheckmate = false;
    public:
        Game();
        void play();
        void setup();
        void move(Player, Piece, int, int, int, int);
        bool isMoveValid(Piece, int, int, int, int);
        bool isCheckmate(Player);
        bool isCheck(Player);
};