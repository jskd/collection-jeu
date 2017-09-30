#include "PlayerRobot.h"

PlayerRobot::PlayerRobot(const std::string name)
  : Player(name)
{
}

PlayerRobot::~PlayerRobot(){
}

PlayerAction PlayerRobot::choiceAction(bool haveEvent, sf::Event e){
  char action = (rand() % (char)(10));
  switch(action)
  {
    case 2:
      return PlayerAction::Up;
    case 4:
      return PlayerAction::Down;
    case 6:
      return PlayerAction::Left;
    case 8:
      return PlayerAction::Right;
    default:
      return PlayerAction::Wait;
    break;
  }
  return PlayerAction::Wait;
}
