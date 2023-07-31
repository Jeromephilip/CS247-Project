#ifndef GAME_H
#define GAME_H


#include "../board/board.h"
#include "../player/player.h"

#include "../window/subject.h"
#include "../window/graphicDisplay.h"
#include "../window/window.h"

#include "../piece/piece.h"
#include "../piece/king.h"
#include "../piece/queen.h"
#include "../piece/rook.h"
#include "../piece/knight.h"
#include "../piece/bishop.h"
#include "../piece/pawn.h"
#include "../player/human.h"
#include "../player/level1.h"
#include "../player/level2.h"
#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <limits>
#include <regex>

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

class Game : public Subject {
    private:
        Player *pW, *pB; 
        int turn; 
        Board b;
        bool isGameDone = false;
        bool isSetupDone = false;
        float blackScore = 0;
        float whiteScore = 0;
        string toLowerCaseString(string);
        void defaultSetup();
        void gameType(stringstream& ss);
        void move(Player*, string, string, bool&, stringstream&);
        void helpMenu();
        void reset();
        void setup();
        bool isMoveValid(Piece*, int, int, int, int);
        void displayScore();
        bool isValidMoveInput(string, string);
        Piece* pawnPromote(string, string);
    public:
        Game();
        void play();
        // bool checkAdjacentKings(int, int);
        bool isCheckmate(string color);
        bool isStalemate(string color);
        bool isCheck(Player *p);
        Board& getBoard(); 
        ~Game();
};

#endif
