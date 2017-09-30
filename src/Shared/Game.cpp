#include "Game.h"
#include "IHM.h"
#include "Board/Piece/Piece.h"
#include "Board/Piece/GraphicsPiece.h"
#include "Board/Board.h"

Game::Game(std::string name, int boardSize, Player& player) :
   _name(name), _board(Board(boardSize)), _player(player)
{
}

const std::string Game::name() const
{
  return _name;
}

Game::~Game()
{
}

void Game::draw(IHM& render)
{
    // Remplissage de l'écran
    render.app()->clear(sf::Color(255, 255, 255));
    // Affiche la grille

    for(int x=0; x< _board.size(); x++)
    {
      for(int y=0; y< _board.size(); y++)
      {
        if(_board.has(Pos2D(x,y)))
        {
          _board.get(Pos2D(x,y))->setSize(render.app()->getSize().x / _board.size());
          _board.get(Pos2D(x,y))->draw(render.app());
        }
      }
    }

    if(_over){
      // Affichage du background
      sf::Sprite sBackground;
      sf::Texture end;
      end.loadFromFile("sprites/end_game.png");
      sBackground.setTexture(end);
      sBackground.setPosition(0, 0);;
      render.app()->draw(sBackground);
    }

    // Affichage de la fenêtre à l'écran
    render.app()->display();
}
