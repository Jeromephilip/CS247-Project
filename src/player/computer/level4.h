#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_
#include "decorator.h"

using namespace std; 

class Level4: public Decorator {
 public:
  Level4( string colour, Computer *component );
  ~Level4(); 
  bool turnMove(int, int, int , int, Piece, Board) override; 
};

#endif
