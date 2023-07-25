#include "decorator.h"

Decorator::Decorator( string colour, bool isComputer, Computer *component ): Computer{colour, isComputer}, component{component} {}

Decorator::~Decorator() { delete component; }
