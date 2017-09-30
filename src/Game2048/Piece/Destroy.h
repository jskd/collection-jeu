#ifndef Destroy2048Piece_H
#define Destroy2048Piece_H

#include "Piece2048.h"


class Destroy2048Piece : public Piece2048 {

  public:
    Destroy2048Piece();
    virtual ~Destroy2048Piece();

    virtual bool onMovedBy(Board* board, Piece* source, Pos2D src);
    virtual bool onMovedTo(Board* board, Piece* target, Pos2D dst);

};

#endif
