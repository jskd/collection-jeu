#ifndef Game2048Variante4_H
#define Game2048Variante4_H

#include "Game2048.h"

class Game2048Variante4 : public Game2048 {

public:
  Game2048Variante4(std::string name, int boardSize, Player& player);
  virtual ~Game2048Variante4();

  virtual Piece2048* pieceRandomDrawing();
};

#endif
