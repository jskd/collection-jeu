#include "Box.h"
#include "../PieceType.h"

SokobanBoxPiece::SokobanBoxPiece()
  : GraphicsPiece(PieceType::BOX ,"sprites/CratePurpleBad.png", "sprites/GroundGravel_Sand.png")
{
}

SokobanBoxPiece::~SokobanBoxPiece()
{
  if(_store)
    delete _store;
}

bool SokobanBoxPiece::isGood() const
{
  if(_store)
    if(_store->type() == PieceType::END_POINT)
      return true;
  return false;
}

bool SokobanBoxPiece::canMovedBy(const Board* board, Piece* source, Pos2D src) const
{
  if(!source)
    return false;

  if(source->type() != PieceType::PLAYER)
    return false;

  Pos2D dir= ( src - pos() ) * -1;

  return board->canMoveRel( (Piece *) this, dir);
}

bool SokobanBoxPiece::onMovedBy(Board* board, Piece* source, Pos2D src)
{
  if(!canMovedBy(board, source, src))
    return false;

  Pos2D dir= ( src - pos() ) * -1;
  board->moveRel( (Piece *) this, dir);
  return false;
}

bool SokobanBoxPiece::onMovedTo(Board* board, Piece* target, Pos2D dst)
{
  board->push(_store, pos());
  _store= board->get(dst);

  if(isGood())
    _texture.loadFromFile("sprites/CratePurpleGood.png");
  else
    _texture.loadFromFile("sprites/CratePurpleBad.png");

  return false;
}

