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
#include "../player/human.h"
#include "../player/level1.h"
#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <limits>

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
        Player *pW, *pB; 
        int turn; 
        Board b;
        bool inCheck = false;
        bool inCheckmate = false;
        void defaultSetup();
        void gameType(stringstream& ss);
        void move(Player*, string, string);
        void helpMenu();
    public:
        Game();
        void play();
        void setup();
        bool isMoveValid(Piece*, int, int, int, int);
        bool isCheckmate(Player *p);
        bool isCheck(Player *p);
        ~Game();
};

#endif