#ifndef GRAPHICSPIECE_H
#define GRAPHICSPIECE_H

#include "Piece.h"
#include <SFML/Graphics.hpp>

class GraphicsPiece : public Piece {

  public:
    GraphicsPiece(int type, const char* textureFile, const char* backgroundFile);
    virtual ~GraphicsPiece();

    virtual void draw(sf::RenderTarget* target) const;

  protected:
    sf::Texture _texture;
    sf::Texture _background;
};

#endif
