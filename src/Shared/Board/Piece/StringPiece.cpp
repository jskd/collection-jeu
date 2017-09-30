#include "StringPiece.h"
#include <cstring>

StringPiece::StringPiece(int type, std::string text, const char* backgroundFile)
  : Piece(type)
{
  _text= text;

  if(strlen(backgroundFile))
  {
    _background.loadFromFile(backgroundFile);
    _background.setSmooth(true);
  }
}

StringPiece::~StringPiece()
{
}

StringPiece& StringPiece::text(std::string text)
{
  _text = text;
  return *this;
}

std::string StringPiece::text()
{
  return _text;
}

void StringPiece::draw(sf::RenderTarget* target) const
{

  int pos_x= _size * pos().x();
  int pos_y= _size * pos().y();

  sf::Font font;
  font.loadFromFile("fonts/verdana.ttf");

  sf::RectangleShape rectangle(sf::Vector2f(_size, _size));
  sf::Text value;
  sf::FloatRect rect;

  // Affichage du background
  sf::Sprite sBackground;
  sBackground.setTexture(_background);
  rect = sBackground.getLocalBounds();
  double ratio_x = _size / rect.width;
  double ratio_y = _size / rect.height;
  sBackground.scale(sf::Vector2f(ratio_x, ratio_y));
  sBackground.setPosition(pos_x, pos_y);;
  target->draw(sBackground);

  rectangle.setPosition(pos_x, pos_y);
  rectangle.setFillColor(sf::Color(255, 255, 255, 0));
  rectangle.setOutlineThickness(2);
  rectangle.setOutlineColor(sf::Color(130, 113, 84));
  target->draw(rectangle);

  // Mise en forme du texte
  value.setFont(font);
  value.setString(_text);
  value.setCharacterSize(30);
  value.setColor(sf::Color(130, 113, 84));
  value.setStyle(sf::Text::Bold);

  // Placement du texte
  rect = value.getLocalBounds();
  value.setOrigin(rect.left + rect.width/2.0f, rect.top + rect.height/2.0f);
  value.setPosition( pos_x + (_size / 2), pos_y + (_size / 2));
  target->draw(value);

}

