#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Sokoban.h"
#include "Piece/Empty.h"
#include "Piece/Wall.h"
#include "Piece/Player.h"
#include "Piece/Box.h"
#include "Piece/EndPoint.h"

using namespace sf;

Sokoban::Sokoban(std::string name, int boardSize, Player& player)
  : Game(name, boardSize, player)
{
  int gridsize = _board.size();
  int n_box_require = 0;

  // Remplisage aléatoire de la grille
  for(int i=0; i < gridsize; i++)
  {
    for(int j=0; j < gridsize; j++)
    {
      int random = rand() % 100;
      if(random < 8)
      {
        _board.push( new SokobanEndPointPiece(), Pos2D(i, j));
        n_box_require++;
      }
      else if(random < 20)
        _board.push( new SokobanWallPiece(), Pos2D(i, j));
      else
        _board.push( new SokobanEmptyPiece(), Pos2D(i, j));
    }
  }

  while(n_box_require != 0)
  {
    Piece* new_box= new SokobanBoxPiece();
    _pieceBox.push_back(new_box);
    while(1)
    {
      Pos2D pos(rand() % _board.size(), rand() % _board.size());
      if(_board.canMoveAbs(new_box, pos))
      {
        _board.moveAbs(new_box , pos);
        n_box_require--;
        break;
      }
    }
  }

  _piecePlayer= new SokobanPlayerPiece();
  while(1)
  {
    Pos2D pos(rand() % _board.size(), rand() % _board.size());
    if(_board.canMoveAbs(_piecePlayer, pos))
    {
      _board.moveAbs(_piecePlayer, pos);
      break;
    }
  }
}

Sokoban::~Sokoban(){
}

void Sokoban::action(bool hasEvent, Event e)
{
    switch(_player.choiceAction(hasEvent, e) ){

      case PlayerAction::Up:
        if(_board.canMoveRel(_piecePlayer, Direction::one_up))
          _board.moveRel(_piecePlayer, Direction::one_up);
      break;

      case PlayerAction::Down :
        if(_board.canMoveRel(_piecePlayer, Direction::one_down))
          _board.moveRel(_piecePlayer, Direction::one_down);
      break;

      case PlayerAction::Left :
        if(_board.canMoveRel(_piecePlayer, Direction::one_left))
          _board.moveRel(_piecePlayer, Direction::one_left);
      break;

      case PlayerAction::Right :
        if(_board.canMoveRel(_piecePlayer, Direction::one_right))
          _board.moveRel(_piecePlayer, Direction::one_right);
      break;

      default:
      break;
    }

  _over= true;
  for(std::vector<Piece*>::iterator it= _pieceBox.begin(); it != _pieceBox.end(); ++it)
  {
      SokobanBoxPiece* ird = dynamic_cast<SokobanBoxPiece*>(*it);
      _over&= ird->isGood();
  }

}
