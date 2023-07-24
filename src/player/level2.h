#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_

#include <string>
#include <cstdlib>

#include "decorator.h"

using namespace std; 

class Level2: public Decorator {
 public:
  Level2( string colour, Computer *component );
  //~Level2(); 
  // Level 2: prefers capturing moves and checks over other moves.
  Move turnMove(int, int, int, int, Board&) override; 
};

#endif
