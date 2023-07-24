#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_
#include "decorator.h"
#include <string>

using namespace std; 

class Level3: public Decorator {
 public:
  Level3( string colour, Computer *component );
  //~Level3(); 
  Move turnMove(int, int, int, int, Board&) override; 
};

#endif
