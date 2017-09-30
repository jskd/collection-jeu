#include "Game2048Variante4.h"
#include "Piece/NumberPiece.h"
#include "Piece/Destroy.h"

Game2048Variante4::Game2048Variante4(std::string name, int boardSize, Player& player)
: Game2048(name, boardSize, player)
{
}

Game2048Variante4::~Game2048Variante4(){
}

Piece2048* Game2048Variante4::pieceRandomDrawing()
{
  if(rand()%2)
    return new NumberPiece2048(2);
  else
    return new Destroy2048Piece();
}
