#include "Number.h"
#include "Empty.h"
#include "TaquinPieceType.h"

TaquinEmptyPiece::TaquinEmptyPiece()
  : GraphicsPiece(TaquinPieceType::NUMBER , "sprites/cross.png", "sprites/GroundGravel_Sand.png")
{
}

TaquinEmptyPiece::~TaquinEmptyPiece()
{
}
