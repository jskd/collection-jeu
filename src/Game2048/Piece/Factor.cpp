#include "Factor.h"
#include "Piece2048Type.h"
#include "Empty.h"
#include "NumberPiece.h"
#include "Destroy.h"

Factor2048Piece::Factor2048Piece(bool divide, int factor)
  : Piece2048(Piece2048Type::FACTOR, ""), _divide(divide), _factor(factor)
{
  text( (divide?"/":"x") +  std::to_string(factor) );
}

Factor2048Piece::~Factor2048Piece()
{
}

bool Factor2048Piece::divide() const
{
  return _divide;
}

int Factor2048Piece::factor() const
{
  return _factor;
}

bool Factor2048Piece::canMovedBy(const Board* board, Piece* source, Pos2D src) const
{
  if(source->type() == Piece2048Type::NUMBER)
    return !dynamic_cast<NumberPiece2048*>(source)->merge();
  else
    return source->type() == Piece2048Type::DESTROY;
}

bool Factor2048Piece::canMovedTo(const Board* board, Piece* target, Pos2D dst) const
{
  if(target->type() == Piece2048Type::NUMBER)
    return !dynamic_cast<NumberPiece2048*>(target)->merge();
  else
    return target->type() == Piece2048Type::EMPTY
      || target->type() == Piece2048Type::DESTROY;
}


bool Factor2048Piece::onMovedBy(Board* board, Piece* source, Pos2D src)
{
  if(source->type() == Piece2048Type::NUMBER)
  {
    NumberPiece2048* p= dynamic_cast<NumberPiece2048*>(source);
    if(divide())
      p->applyDivide(factor());
    else
      p->applyMult(factor());
    p->merge(true);
  }
  else if(source->type() == Piece2048Type::DESTROY)
  {
    Destroy2048Piece* p= dynamic_cast<Destroy2048Piece*>(source);
    p->destroyRequest();
  }
  delete this;
  return false;
}

bool Factor2048Piece::onMovedTo(Board* board, Piece* target, Pos2D dst)
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

