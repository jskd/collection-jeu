#ifndef Empty2048PiecePiece_H
#define Empty2048PiecePiece_H

#include "Piece2048.h"


class Empty2048Piece : public Piece2048 {

  public:
    Empty2048Piece();
    virtual ~Empty2048Piece();

    virtual bool canMovedTo(const Board* board, Piece* target, Pos2D dst) const;
    virtual bool onMovedBy(Board* board, Piece* source, Pos2D src);

};

#endif
