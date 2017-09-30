#ifndef Game2048Variante3_H
#define Game2048Variante3_H

#include "Game2048.h"

class Game2048Variante3 : public Game2048 {

public:
  Game2048Variante3(std::string name, int boardSize, Player& player);
  virtual ~Game2048Variante3();

  virtual Piece2048* pieceRandomDrawing();
};

#endif
