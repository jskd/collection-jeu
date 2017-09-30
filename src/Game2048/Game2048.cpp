#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Game2048.h"
#include "../Shared/Board/Pos2D.h"
#include "Piece/NumberPiece.h"
#include "Piece/Empty.h"
#include "Piece/Piece2048Type.h"

using namespace sf;

static std::vector<Pos2D> _getEmptyPieceList(const Board* board)
{
  std::vector<Pos2D> listPos;
  for(int x=0; x< board->size(); x++)
  {
    for(int y=0; y< board->size(); y++)
    {
      Pos2D pos= Pos2D(x,y);
      if(board->has(pos))
      {
        Piece2048* cursor= dynamic_cast<Piece2048*>(board->get(pos));
        if(cursor)
          if(cursor->type() == Piece2048Type::EMPTY)
            listPos.push_back(pos);
      }
    }
  }
  return listPos;
}

static void _addRandomPiece(Board* board, std::vector<Pos2D> list ,Piece* piece)
{
  int random= rand() % list.size();
  board->push(piece, list[random]);
}

Game2048::Game2048(std::string name, int boardSize, Player& player)
  : Game(name, boardSize, player)
{
  // Remplisage aléatoire de la grille
  for(int i=0; i < boardSize; i++){
    for(int j=0; j < boardSize; j++){
      _board.moveAbs( new Empty2048Piece(), Pos2D(i, j));
    }
  }

  std::vector<Pos2D> list= _getEmptyPieceList(&_board);
  if(list.size() > 0)
    _addRandomPiece(&_board, list, pieceRandomDrawing());
}

Game2048::~Game2048(){
}

Piece2048* Game2048::pieceRandomDrawing()
{
  return new NumberPiece2048(2);
}

void Game2048::action(bool hasEvent, Event e)
{
  Pos2D dir= Pos2D(0,0);

    switch(_player.choiceAction(hasEvent, e) ){
      case PlayerAction::Up:
        dir= Direction::one_up;
      break;
      case PlayerAction::Down:
        dir= Direction::one_down;
      break;
      case PlayerAction::Left:
        dir= Direction::one_left;
      break;
      case PlayerAction::Right:
        dir= Direction::one_right;
      break;
      default:
        return;
      break;
    }

    int x, xIter;
    if(dir.x() > 0) {
      x= _board.size()-1;
      xIter= -1;
    } else {
      x= 0;
      xIter= 1;
    }
    for(; x >= 0 && x < _board.size(); x+= xIter)
    {
      int y, yIter;
      if(dir.y() > 0) {
        y= _board.size()-1;
        yIter= -1;
      } else {
        y= 0;
        yIter= 1;
      }
      for(; y >= 0 && y < _board.size(); y+= yIter)
      {
        Pos2D pos= Pos2D(x,y);
        if(_board.has(pos))
        {
          Piece2048* cursor= dynamic_cast<Piece2048*>(_board.get(pos));
          if(cursor)
          {
            cursor->merge(false);
            while(_board.canMoveRel(cursor, dir))
            {
              _board.moveRel(cursor, dir);
              if(cursor->isDestroy())
              {
                delete cursor;
                break;
              }
            }
          }
        }
      }
    }

  std::vector<Pos2D> list= _getEmptyPieceList(&_board);
  if(list.size() > 0)
  {
    _addRandomPiece(&_board, list, pieceRandomDrawing());
    _over= false;
  }
  else
  {
    // check end game
    for(int x=0; x<_board.size(); x++)
    {
      for(int y=0; y<_board.size(); y++)
      {
        Pos2D pos(x,y);
        if(_board.has(pos))
        {
          Piece2048* cursor= dynamic_cast<Piece2048*>(_board.get(pos));
          if(cursor)
          {
            if( _board.canMoveRel(cursor, Direction::one_up)
              || _board.canMoveRel(cursor, Direction::one_left)
              || _board.canMoveRel(cursor, Direction::one_right)
              || _board.canMoveRel(cursor, Direction::one_down))
              return;
          }
        }
      }
    }
    _over= true;
  }
}
