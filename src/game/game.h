#ifndef GAME_H
#define GAME_H


#include "../board/board.h"
#include "../player/player.h"
#include "../piece/piece.h"
#include "../piece/king.h"
#include "../piece/queen.h"
#include "../piece/rook.h"
#include "../piece/knight.h"
#include "../piece/bishop.h"
#include "../piece/pawn.h"
#include <iostream>

using namespace std;

class Game {
    private:
        Board b;
        bool inCheck = false;
        bool inCheckmate = false;
        void defaultSetup();
    public:
        Game();
        void play();
        void setup();
        void move(int, int, int, int);
        bool isMoveValid(int, int, int, int);
        bool isCheckmate();
        bool isCheck();
};

#endif