#ifndef TAQUIN_H
#define TAQUIN_H

#include <string>
#include "../Shared/Game.h"
#include "Piece/Empty.h"
#include "Piece/Number.h"
#include "../Shared/Board/Pos2D.h"

class Taquin : public Game {

public:
  Taquin(std::string name, int boardSize, Player& player);
  virtual ~Taquin();

  virtual void action(bool haveEvent, sf::Event e);

private:
  Pos2D _cursorPos=Pos2D(0,0);
};

#endif
