#ifndef _LEVELONE_H_
#define _LEVELONE_H_

#include <stdlib.h>

#include "computer.h"


class Level1: public Computer {
    public:
    Level1(string); 
    //~Level1(); 
    // random moves
    Move turnMove(int, int, int, int, Board&) override; 
};

#endif
