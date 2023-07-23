#include "player.h"

Player::Player(string colour) : colour{colour} {}

Player::~Player() {}

string Player::getColour() {
    return colour; 
}
