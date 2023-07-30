#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_

#include <string>
#include <cstdlib>

//#include "decorator.h"
#include "computer.h"

using namespace std; 

class Level2: public Computer {
 public:
  Level2( string colour, bool );
  //~Level2(); 
  // Level 2: prefers capturing moves and checks over other moves.
  Move turnMove(int, int, int, int, Board&) override; 
};

#endif
