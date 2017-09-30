#include "Game2048Variante2.h"
#include "Piece/NumberPiece.h"

Game2048Variante2::Game2048Variante2(std::string name, int boardSize, Player& player)
: Game2048(name, boardSize, player)
{
}

Game2048Variante2::~Game2048Variante2(){
}

Piece2048* Game2048Variante2::pieceRandomDrawing()
{
  // factor de 2 ou -2
  int factor= (rand()%2)?-2:2;
  return new NumberPiece2048(factor);
}
