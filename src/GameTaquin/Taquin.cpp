#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Taquin.h"
#include "../Shared/Board/Pos2D.h"
#include "Piece/TaquinPieceType.h"

using namespace sf;

Taquin::Taquin(std::string name, int boardSize, Player& player)
  : Game(name, boardSize, player)
{

  std::vector<int> numbers;
  int gridsize = _board.size();
  for(int i=0; i < (gridsize * gridsize); i++){
    numbers.push_back(i);
  }

  // Remplisage aléatoire de la grille
  for(int i=0; i < gridsize; i++){
    for(int j=0; j < gridsize; j++){

        int random = rand() % numbers.size();
        int choice = numbers[random];
        numbers.erase(numbers.begin() + (random));

        Pos2D pos= Pos2D(i, j);

        if(choice > 0)
          _board.moveAbs( new TaquinNumberPiece(choice), pos);
        else{
          _cursorPos= pos;
          _board.moveAbs( new TaquinEmptyPiece(), pos);
        }
    }
  }
}

Taquin::~Taquin(){
}

static void _switchPiece(Board* b, Pos2D posA, Pos2D posB) {
  Piece* p= b->get(posA);
  b->moveAbs(b->get(posB), posA);
  b->moveAbs(p, posB);
}

static bool _canSwitchPiece(Board* b, Pos2D posA, Pos2D posB) {
  return posA.x() >= 0 && posA.x() < b->size()
      && posA.y() >= 0 && posA.y() < b->size()
      && posB.x() >= 0 && posB.x() < b->size()
      && posB.y() >= 0 && posB.y() < b->size();
}

void Taquin::action(bool hasEvent, Event e)
{
    Pos2D dst= _cursorPos;

    switch(_player.choiceAction(hasEvent, e) ){
      case PlayerAction::Up:
        dst= _cursorPos + Direction::one_down;
      break;
      case PlayerAction::Down:
        dst= _cursorPos + Direction::one_up;
      break;
      case PlayerAction::Left:
        dst= _cursorPos + Direction::one_right;
      break;
      case PlayerAction::Right:
        dst= _cursorPos + Direction::one_left;
      break;
      default:
      break;
    }

  if(_canSwitchPiece(&_board, dst, _cursorPos))
  {
    _switchPiece(&_board, dst, _cursorPos);
    _cursorPos= dst;
  }

  for(int x=0; x<_board.size(); x++)
  {
    for(int y=0; y<_board.size(); y++)
    {
      if(!_board.has(Pos2D(x,y)))
        continue;

      Piece* p= _board.get(Pos2D(x,y));
      if(p->type() == TaquinPieceType::NUMBER)
      {
        TaquinNumberPiece* number= dynamic_cast<TaquinNumberPiece*>(p);
        if(!number)
          continue;

        if(number->value() != x+y*_board.size()+1)
        {
          _over= false;
          return;
        }
      }
      else
      {
        if(x != _board.size()-1 && y != _board.size()-1)
        {
          _over= false;
          return;
        }
      }
    }
  }
  _over= true;
}
