#include "Empty.h"
#include "../PieceType.h"

SokobanEmptyPiece::SokobanEmptyPiece()
  : GraphicsPiece(PieceType::EMPTY, "", "sprites/GroundGravel_Sand.png")
{
}

SokobanEmptyPiece::~SokobanEmptyPiece()
{
}
