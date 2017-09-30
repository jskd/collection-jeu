#include "Piece2048.h"
#include "NumberPiece.h"
#include "Piece2048Type.h"
#include "Empty.h"
#include "Destroy.h"
#include "Factor.h"

#include <stdio.h>
#include <iomanip>
#include <sstream>


NumberPiece2048::NumberPiece2048(float factor)
 : Piece2048( Piece2048Type::NUMBER, std::to_string(factor)), _factor(abs(factor))
{
  _value= abs(_factor);
  _signed= factor < 0;
  switch(_factor)
  {
    case 2:
      Piece2048::StringPiece::_background.loadFromFile("sprites/Mult2.png");
      break;
    case 3:
      Piece2048::StringPiece::_background.loadFromFile("sprites/Mult3.png");
      break;
    case 4:
      Piece2048::StringPiece::_background.loadFromFile("sprites/Mult4.png");
      break;
  }
  updateText();
}

NumberPiece2048::~NumberPiece2048()
{
}

float NumberPiece2048::value() const
{
  return _value;
}

int NumberPiece2048::factor() const
{
  return _factor;
}

bool NumberPiece2048::isSigned() const
{
  return _signed;
}

NumberPiece2048& NumberPiece2048::updateText()
{
  std::ostringstream out;
  out << (isSigned()?"-":"") << std::setprecision(3) << _value;

  text(out.str());
  return *this;
}

NumberPiece2048& NumberPiece2048::increase()
{
  _value = _value * _factor;
  updateText();
  return *this;
}

NumberPiece2048& NumberPiece2048::applyMult(int factor)
{
  _value *= factor;
  updateText();
  return *this;
}

NumberPiece2048& NumberPiece2048::applyDivide(int factor)
{
  _value /= factor;
  updateText();
  return *this;
}

bool NumberPiece2048::canMovedBy(const Board* board, Piece* source, Pos2D src) const
{
  if(source->type() == Piece2048Type::NUMBER)
  {
    NumberPiece2048* number= dynamic_cast<NumberPiece2048*>(source);
    if(number->factor() == factor()
        && number->value() == value()
        && !number->merge() && !merge())
      return true;
  }
  else if(source->type() == Piece2048Type::DESTROY)
  {
    return true;
  }
  else if(source->type() == Piece2048Type::FACTOR)
  {
    return true;
  }
  return false;
}

bool NumberPiece2048::onMovedBy(Board* board, Piece* source, Pos2D src)
{
  if(source->type() == Piece2048Type::NUMBER)
  {
    NumberPiece2048* p= dynamic_cast<NumberPiece2048*>(source);
    if(p->isSigned() != isSigned())
      p->destroyRequest();
    else
      p->increase().merge(true);
  }
  else if(source->type() == Piece2048Type::DESTROY)
  {
    Destroy2048Piece* destroy= dynamic_cast<Destroy2048Piece*>(source);
    destroy->destroyRequest();
  }
  else if(source->type() == Piece2048Type::FACTOR)
  {
    Factor2048Piece* p= dynamic_cast<Factor2048Piece*>(source);
    if(p->divide())
      applyDivide(p->factor());
    else
      applyMult(p->factor());
    merge(true);
    p->destroyRequest();
  }
  delete this;
  return false;
}

bool NumberPiece2048::canMovedTo(const Board* board, Piece* target, Pos2D dst) const
{
  return true;
}

bool NumberPiece2048::onMovedTo(Board* board, Piece* target, Pos2D dst)
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

