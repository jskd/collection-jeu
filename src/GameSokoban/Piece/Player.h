#ifndef SokobanPlayerPiece_H
#define SokobanPlayerPiece_H

#include "../../Shared/Board/Piece/GraphicsPiece.h"

class SokobanPlayerPiece : public GraphicsPiece {

  public:
    SokobanPlayerPiece();

    Piece * _store= nullptr;

    virtual ~SokobanPlayerPiece();

    virtual bool onMovedTo(Board* board, Piece* target, Pos2D dst);
};

#endif
