#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerAction.h"
#include <string>
#include <SFML/Graphics.hpp>


class Player{
public:

  Player(std::string name);
  virtual ~Player();

  const std::string getName();
  virtual PlayerAction choiceAction(bool haveEvent, sf::Event e)= 0;

private:

  const std::string _name;

};

#endif
