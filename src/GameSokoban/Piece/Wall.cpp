#include "Wall.h"
#include "../PieceType.h"

SokobanWallPiece::SokobanWallPiece()
  : GraphicsPiece(PieceType::WALL , "sprites/WallRound_Brown.png", "sprites/GroundGravel_Sand.png")
{
}

SokobanWallPiece::~SokobanWallPiece()
{
}

bool SokobanWallPiece::canMovedBy(const Board* board, Piece* source, Pos2D src) const
{
  return false;
}
