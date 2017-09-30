#ifndef PLAYER_HUMAN_H
#define PLAYER_HUMAN_H

#include "Player.h"

class PlayerHuman : public Player {

public:

  PlayerHuman(const std::string name);
  virtual ~PlayerHuman();
  
  virtual PlayerAction choiceAction(bool haveEvent, sf::Event e);
};
#endif
