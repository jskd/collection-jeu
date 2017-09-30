#ifndef Game2048VarianteAll_H
#define Game2048VarianteAll_H

#include "Game2048.h"

class Game2048VarianteAll : public Game2048 {

public:
  Game2048VarianteAll(std::string name, int boardSize, Player& player);
  virtual ~Game2048VarianteAll();

  virtual Piece2048* pieceRandomDrawing();
};

#endif
