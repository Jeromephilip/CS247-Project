#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "computer.h"

class Decorator: public Computer {
 protected:
  Computer *component;
 public:
  Decorator( string colour, Computer *component );
  virtual ~Decorator();
};

#endif
