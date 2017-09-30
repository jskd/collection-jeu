#ifndef Factor2048Piece_H
#define Factor2048Piece_H

#include "Piece2048.h"


class Factor2048Piece : public Piece2048 {

  public:
    Factor2048Piece(bool divide, int factor);
    virtual ~Factor2048Piece();

    virtual bool canMovedBy(const Board* board, Piece* source, Pos2D src) const;
    virtual bool canMovedTo(const Board* board, Piece* target, Pos2D dst) const;

    virtual bool onMovedBy(Board* board, Piece* source, Pos2D src);
    virtual bool onMovedTo(Board* board, Piece* target, Pos2D dst);

    bool divide() const;
    int factor() const;

  private:
    const bool _divide;
    const int _factor;
};

#endif
