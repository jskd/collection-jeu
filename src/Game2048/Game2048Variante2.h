#ifndef Game2048Variante2_H
#define Game2048Variante2_H

#include "Game2048.h"

class Game2048Variante2 : public Game2048 {

public:
  Game2048Variante2(std::string name, int boardSize, Player& player);
  virtual ~Game2048Variante2();

  virtual Piece2048* pieceRandomDrawing();
};

#endif
