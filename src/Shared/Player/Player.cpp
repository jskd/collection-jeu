#include <iostream>
#include "Player.h"

Player::Player(std::string name)
  : _name(name)
{
}

Player::~Player(){
}

const std::string Player::getName(){
  return _name;
}
