#include "Destroy.h"
#include "Piece2048Type.h"
#include "Empty.h"

Destroy2048Piece::Destroy2048Piece()
  : Piece2048(Piece2048Type::DESTROY, "")
{
  Piece2048::StringPiece::_background.loadFromFile("sprites/Destroy.png");
}

Destroy2048Piece::~Destroy2048Piece()
{
}

bool Destroy2048Piece::onMovedBy(Board* board, Piece* source, Pos2D src)
{
  Piece2048* p= dynamic_cast<Piece2048*>(source);
  p->destroyRequest();
  delete this;
  return false;
}

bool Destroy2048Piece::onMovedTo(Board* board, Piece* target, Pos2D dst)
{
  if(isDestroy())
  {
    board->push(new Empty2048Piece(), pos());
    board->push(new Empty2048Piece(), dst);
    return true;
  }
  board->push(new Empty2048Piece(), pos());
  return false;
}

