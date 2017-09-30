#ifndef SOKOBAN_H
#define SOKOBAN_H

#include "../Shared/Game.h"
#include <vector>

class Sokoban : public Game {

public:
  Sokoban(std::string name, int boardSize, Player& player);
  virtual ~Sokoban();

  virtual void action(bool haveEvent, sf::Event e);

private:
  Piece* _piecePlayer;
  std::vector<Piece*> _pieceBox;
};

#endif
