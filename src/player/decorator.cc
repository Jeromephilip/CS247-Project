#include "decorator.h"

Decorator::Decorator( string colour, Computer *component ): Computer{colour}, component{component} {}

Decorator::~Decorator() { delete component; }
