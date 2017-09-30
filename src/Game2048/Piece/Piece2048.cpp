#include "Piece2048.h"
#include "Piece2048Type.h"

Piece2048::Piece2048(int type, std::string value)
  : StringPiece(type , value, "sprites/GroundGravel_Sand.png")
{
}

Piece2048::~Piece2048()
{
}


bool Piece2048::merge() const
{
  return _merge;
}

Piece2048& Piece2048::merge( bool merge )
{
  _merge= merge;
  return *this;
}

bool Piece2048::isDestroy() const
{
  return _destroy;
}

void Piece2048::destroyRequest()
{
  _destroy = true;
}


