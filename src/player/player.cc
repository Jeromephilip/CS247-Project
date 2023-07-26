#include "player.h"

Player::Player(string colour, bool isComputer) : colour{colour}, isComputer{isComputer} {}

Player::~Player() {}

string Player::getColour() {
    return colour; 
}

bool Player::getBool() {
    return isComputer; 
}
