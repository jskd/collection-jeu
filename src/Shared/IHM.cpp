#include "IHM.h"

using namespace sf;

IHM::IHM(int window_size, const std::string& title)
  : _window_size(window_size) {
  _app = new RenderWindow(VideoMode(_window_size, _window_size, 32), title, sf::Style::Titlebar | sf::Style::Close);
}

IHM::~IHM() {
  _app->close();
  delete _app;
}

sf::RenderWindow* IHM::app() {
  return _app;
}

int IHM::window_size() {
  return _window_size;
}
