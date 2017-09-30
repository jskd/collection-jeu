#ifndef SokobanWallPiece_H
#define SokobanWallPiece_H

#include "../../Shared/Board/Piece/GraphicsPiece.h"

class SokobanWallPiece : public GraphicsPiece {

  public:
    SokobanWallPiece();
  
    virtual ~SokobanWallPiece();

    virtual bool canMovedBy(const Board* board, Piece* source, Pos2D src) const;
};

#endif
