#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_
#include "decorator.h"
#include <string>

using namespace std; 

class Level2: public Decorator {
 public:
  Level2( string colour, Computer *component );
  ~Level2(); 
  Move turnMove(int, int, int , int, Piece, Board) override; 
};

#endif
