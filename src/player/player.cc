#include "player.h"

Player::Player(string colour, bool isComputer) : colour{colour, isComputer} {}

Player::~Player() {}

string Player::getColour() {
    return colour; 
}
