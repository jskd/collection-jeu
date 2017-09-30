#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include "../Board.h"
#include "../Pos2D.h"

class Piece {

  public:
    Piece(int type);

    virtual ~Piece();

    int type() const;
    Pos2D pos() const;
    virtual void draw(sf::RenderTarget* target) const;
    virtual bool canMovedBy(const Board* board, Piece* source, Pos2D src) const;
    // return true stop event
    virtual bool onMovedBy(Board* board, Piece* source, Pos2D src);
    virtual bool canMovedTo(const Board* board, Piece* target, Pos2D dst) const;
    // return true stop event
    virtual bool onMovedTo(Board* board, Piece* target, Pos2D dst);

    void setSize(int size);
    void setPos(Pos2D pos);

  protected:
    const int _type;
    int _size = 0;
    Pos2D _pos;

};

#endif
