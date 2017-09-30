#include "Number.h"
#include "TaquinPieceType.h"

TaquinNumberPiece::TaquinNumberPiece(const int value)
  : StringPiece(TaquinPieceType::NUMBER , std::to_string(value), "sprites/GroundGravel_Sand.png"), _value(value)
{
}

TaquinNumberPiece::~TaquinNumberPiece()
{
}

int TaquinNumberPiece::value() const
{
  return _value;
}
