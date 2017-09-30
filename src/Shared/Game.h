#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../Shared/Player/Player.h"
#include "../Shared/Board/Board.h"

class IHM;

class Game{

public:

  Game(std::string name, int gridSize, Player& player);
  virtual ~Game();

  const std::string name() const;
  virtual void action(bool hasEvent, sf::Event e)=0;
  void draw(IHM& render);
  bool isOver() const;

protected:

  const std::string _name;
  Board _board;
  Player& _player;
  bool _over= false;

};

#endif
