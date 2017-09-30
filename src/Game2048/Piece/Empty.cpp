#include "Empty.h"
#include "Piece2048Type.h"

Empty2048Piece::Empty2048Piece()
  : Piece2048(Piece2048Type::EMPTY, "")
{
}

Empty2048Piece::~Empty2048Piece()
{
}

bool Empty2048Piece::canMovedTo(const Board* board, Piece* target, Pos2D dst) const
{
  return false;
}

bool Empty2048Piece::onMovedBy(Board* board, Piece* source, Pos2D src)
{
  delete this;
  return false;
}



