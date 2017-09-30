#include "PlayerHuman.h"

using namespace sf;

PlayerHuman::PlayerHuman(const std::string name)
  : Player(name)
{
}

PlayerHuman::~PlayerHuman(){
}

PlayerAction PlayerHuman::choiceAction(bool haveEvent, sf::Event e){
  if(!haveEvent)
    return PlayerAction::Wait;
  if(e.type == Event::KeyPressed){
    switch(e.key.code)
    {
      case Keyboard::Up:
        return PlayerAction::Up;
      case Keyboard::Down:
        return PlayerAction::Down;
      case Keyboard::Left:
        return PlayerAction::Left;
      case Keyboard::Right:
        return PlayerAction::Right;
      default:
        return PlayerAction::Wait;
      break;
    }
  }
  return PlayerAction::Wait;
}
