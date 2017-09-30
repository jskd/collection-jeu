#include "Player.h"
#include "../PieceType.h"

SokobanPlayerPiece::SokobanPlayerPiece()
  : GraphicsPiece(PieceType::PLAYER, "sprites/PlayerDown.png", "sprites/GroundGravel_Sand.png")
{
}

SokobanPlayerPiece::~SokobanPlayerPiece()
{
  if(_store)
    delete _store;
}

bool SokobanPlayerPiece::onMovedTo(Board* board, Piece* target, Pos2D dst)
{
  board->push(_store, pos());
  _store= board->get(dst);

  Pos2D dir= (pos() - dst) * -1;

  if( dir ==  Direction::one_up)
  _texture.loadFromFile("sprites/PlayerUp.png");
  if( dir ==  Direction::one_down)
  _texture.loadFromFile("sprites/PlayerDown.png");
  if( dir ==  Direction::one_left)
  _texture.loadFromFile("sprites/PlayerLeft.png");
  if( dir ==  Direction::one_right)
  _texture.loadFromFile("sprites/PlayerRight.png");

  return false;
}

