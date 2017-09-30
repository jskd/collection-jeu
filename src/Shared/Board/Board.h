#ifndef BOARD_H
#define BOARD_H

#include "Pos2D.h"

class Piece;

class Board{

public:
  Board(int size);
  ~Board();

  bool hasPos(Pos2D pos) const;
  bool has(Pos2D pos) const;
  Piece* get(Pos2D pos) const;
  int size() const;

  bool canMoveAbs(Piece* c, Pos2D pos) const;
  void moveAbs(Piece* c, Pos2D pos);

  bool canMoveRel(Piece* c, Pos2D dir) const;
  void moveRel(Piece* c, Pos2D dir);

  void push(Piece* c, Pos2D pos);
  void pull(Pos2D pos);

private:
  int _size = 0;
  Piece*** _matrice;

};

#endif
