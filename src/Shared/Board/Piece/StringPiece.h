#ifndef STRINGPIECE_H
#define STRINGPIECE_H

#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <string>

class StringPiece : public Piece {

  public:
    StringPiece(int type, std::string text, const char* backgroundFile);
    virtual ~StringPiece();

    StringPiece& text(std::string text);
    std::string text();

    virtual void draw(sf::RenderTarget* target) const;

  protected:
    std::string _text;
    sf::Texture _background;
};

#endif
