#ifndef IHM_H
#define IHM_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"

class IHM {

public:

  IHM(int window_size, const std::string& title);
  virtual ~IHM();

  sf::RenderWindow* app();
  int window_size();
  void drawGame(const Game& game);

private:

  int _window_size = 0;
  sf::RenderWindow* _app;

};

std::ostream& operator<<(std::ostream& out, const Board& board);
std::ostream& operator<<(std::ostream& out, const Piece& piece);

#endif
