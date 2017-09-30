#include <iostream>
#include "Board.h"
#include "Piece/Piece.h"
#include "Pos2D.h"
#include "../../GameSokoban/Piece/Empty.h"

Board::Board(int size)
  : _size(size)
{
  _matrice= new Piece**[_size];
  for(int x=0; x<_size; x++)
  {
    _matrice[x]= new Piece*[_size];
    for(int y=0; y<_size; y++)
      _matrice[x][y]= nullptr;
  }
}

Board::~Board(){
  for(int x=0; x<size(); x++)
  {
    for(int y=0; y<size(); y++)
      if(_matrice[x][y])
        delete _matrice[x][y];
    delete[] _matrice[x];
  }
  delete[] _matrice;
}

bool Board::hasPos(Pos2D pos) const
{
  if(!(pos.x() < size() && pos.x() >= 0 && pos.y() < size() && pos.y() >= 0))
    return false;
  return true;
}

bool Board::has(Pos2D pos) const
{
  if(!hasPos(pos))
    throw "Board::has(Pos2D pos): Pos not exist";
  return _matrice[pos.x()][pos.y()];
}
Piece* Board::get(Pos2D pos) const
{
  return _matrice[pos.x()][pos.y()];
}

int Board::size() const
{
  return _size;
}

void Board::push(Piece* piece, const Pos2D pos)
{
  if(!hasPos(pos))
    return;

  if(has(pos))
    pull(pos);

  _matrice[pos.x()][pos.y()] = piece;

  if(piece)
  {
    piece->setPos(pos);
  }
}

void Board::pull(Pos2D pos)
{
  if(!hasPos(pos))
    return;

  _matrice[pos.x()][pos.y()] = nullptr;
}

bool Board::canMoveAbs(Piece* piece, Pos2D pos) const
{
  if(!hasPos(pos))
   return false;

  if(piece && has(pos))
  {
    return (get(pos)->canMovedBy(this, piece, piece->pos())
      && piece->canMovedTo(this, get(pos), pos));
  }
  return true;
}

void Board::moveAbs(Piece* piece, Pos2D pos)
{
  if(!hasPos(pos))
    throw "pos not found";

  if(piece && has(pos))
  {
    if(get(pos)->onMovedBy(this, piece, piece->pos()))
      return; // il onMoveBy stopped move action
    if(piece->onMovedTo(this, get(pos), pos))
      return;
  }

  push(piece, pos);
}

bool Board::canMoveRel(Piece* piece, Pos2D dir) const
{
  return canMoveAbs(piece, piece->pos() + dir);
}

void Board::moveRel(Piece* piece, Pos2D dir)
{
  moveAbs(piece, piece->pos() + dir);
}
