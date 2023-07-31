#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Observer {
  public:
    virtual void notify() = 0;
    virtual ~Observer() = 0;
};

#endif
