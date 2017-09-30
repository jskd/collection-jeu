#include "Game2048Variante3.h"
#include "Piece/NumberPiece.h"
#include "Piece/Factor.h"

Game2048Variante3::Game2048Variante3(std::string name, int boardSize, Player& player)
: Game2048(name, boardSize, player)
{
}

Game2048Variante3::~Game2048Variante3(){
}

Piece2048* Game2048Variante3::pieceRandomDrawing()
{
  if(rand()%2)
    return new NumberPiece2048(2);
  else if(rand()%2)
    return new Factor2048Piece(false, 2);
  else
    return new Factor2048Piece(true, 2);
}
