#include "Game2048Variante1.h"
#include "Piece/NumberPiece.h"

Game2048Variante1::Game2048Variante1(std::string name, int boardSize, Player& player)
: Game2048(name, boardSize, player)
{
}

Game2048Variante1::~Game2048Variante1(){
}

Piece2048* Game2048Variante1::pieceRandomDrawing()
{
  // factor de 2 à 4
  int factor= 2 + rand()%3;
  return new NumberPiece2048(factor);
}
