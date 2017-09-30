#ifndef SokobanBoxPiece_H
#define SokobanBoxPiece_H

#include "../../Shared/Board/Piece/GraphicsPiece.h"

class SokobanBoxPiece : public GraphicsPiece {

  public:
    SokobanBoxPiece();

    virtual ~SokobanBoxPiece();

    bool isGood() const;

    virtual bool canMovedBy(const Board* board, Piece* source, Pos2D src) const;

    virtual bool onMovedBy(Board* board, Piece* source, Pos2D src);

    virtual bool onMovedTo(Board* board, Piece* target, Pos2D dst);

    private:
      Piece* _store;
};

#endif
