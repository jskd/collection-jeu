#ifndef PLAYER_ROBOT_H
#define PLAYER_ROBOT_H

#include "Player.h"

class PlayerRobot : public Player {

public:

  PlayerRobot(const std::string name);
  virtual ~PlayerRobot();

  virtual PlayerAction choiceAction(bool haveEvent, sf::Event e);
  
};
#endif
