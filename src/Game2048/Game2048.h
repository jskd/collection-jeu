#ifndef GAME_2048_GAME_2048_H
#define GAME_2048_GAME_2048_H

#include <string>
#include "../Shared/Game.h"
#include "../Shared/Board/Pos2D.h"

class Piece2048;

class Game2048 : public Game {

public:
  Game2048(std::string name, int boardSize, Player& player);
  virtual ~Game2048();

  virtual void action(bool haveEvent, sf::Event e);

  virtual Piece2048* pieceRandomDrawing();
};

#endif
