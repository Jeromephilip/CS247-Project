#ifndef GAME_H
#define GAME_H


#include "../board/board.h"
#include "../player/player.h"
#include <iostream>

using namespace std;

class Game {
    private:
        Board b;
        bool inCheck = false;
        bool inCheckmate = false;
    public:
        Game();
        void play();
        void setup();
        void move(Player, Piece*, int, int, int, int);
        bool isMoveValid(Piece*, int, int, int, int);
        bool isCheckmate(Player);
        bool isCheck(Player);
};

#endif