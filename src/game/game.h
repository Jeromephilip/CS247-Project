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

/*struct Move {
    int oldX; 
    int oldY; 
    int newX; 
    int newY; 
    bool valid; 
    Piece* piece; 
}; */

class Player;

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
        void move(Player*, int, int, int, int);
        bool isMoveValid(int, int, int, int);
        bool isCheckmate(Player*);
        bool isCheck(Player*);
};

#endif