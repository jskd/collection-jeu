#include "EndPoint.h"
#include "../PieceType.h"

SokobanEndPointPiece::SokobanEndPointPiece()
  : GraphicsPiece(PieceType::END_POINT ,"sprites/EndPoint_Purple.png", "sprites/GroundGravel_Sand.png")
{
}

SokobanEndPointPiece::~SokobanEndPointPiece()
{
}
