#ifndef _LEVELONE_H_
#define _LEVELONE_H_
#include "computer.h"

class Level1: public Computer {
    public:
    Level1(string); 
    ~Level1(); 
    Move turnMove(int, int, int , int, Piece, Board) override; 
};

#endif
