#include "Piece.h"
#include "../Pos2D.h"

Piece::Piece(int type)
  : _type(type), _pos(-1,-1)
{
}

Piece::~Piece()
{
}

int Piece::type() const
{
  return _type;
}

Pos2D Piece::pos() const
{
  return _pos;
}

void Piece::setSize(int size)
{
  _size = size;
}

void Piece::setPos(Pos2D pos)
{
  _pos= pos;
}

void Piece::draw(sf::RenderTarget* target) const
{
}

bool Piece::canMovedBy(const Board* board, Piece* source, Pos2D src) const
{
  return true;
}

bool Piece::onMovedBy(Board* board, Piece* source, Pos2D src)
{
  return false;
}

bool Piece::canMovedTo(const Board* board, Piece* target, Pos2D dst) const
{
  return true;
}

bool Piece::onMovedTo(Board* board, Piece* target, Pos2D dst)
{
  return false;
}
