#ifndef Game2048Variante1_H
#define Game2048Variante1_H

#include "Game2048.h"

class Game2048Variante1 : public Game2048 {

public:
  Game2048Variante1(std::string name, int boardSize, Player& player);
  virtual ~Game2048Variante1();

  virtual Piece2048* pieceRandomDrawing();
};

#endif
