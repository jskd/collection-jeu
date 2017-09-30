#include "Game2048VarianteAll.h"
#include "Piece/NumberPiece.h"
#include "Piece/Destroy.h"
#include "Piece/Factor.h"

Game2048VarianteAll::Game2048VarianteAll(std::string name, int boardSize, Player& player)
: Game2048(name, boardSize, player)
{
}

Game2048VarianteAll::~Game2048VarianteAll(){
}

Piece2048* Game2048VarianteAll::pieceRandomDrawing()
{
  switch(rand()%10)
  {
    case 0:
      return new NumberPiece2048(2);
    case 1:
      return new NumberPiece2048(3);
    case 2:
      return new NumberPiece2048(4);
    case 3:
      return new NumberPiece2048(-2);
    case 4:
      return new NumberPiece2048(-3);
    case 5:
      return new NumberPiece2048(-4);
    case 6:
      return new Destroy2048Piece();
    case 7:
      return new Factor2048Piece(false, 2);
    case 8:
      return new Factor2048Piece(true, 2);
    default:
      return new NumberPiece2048(2);
  }
}
