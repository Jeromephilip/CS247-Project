#ifndef _COMPUTER_
#define _COMPUTER_

#include "../player/player.h"

class Computer : public Player{
    public: 
    Computer(string, bool);
    virtual ~Computer();
    virtual Move turnMove(int, int, int, int, Board&) = 0; 
}; 

#endif
