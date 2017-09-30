#include <iostream>
#include <cstring>
#include <cstdlib>

#include "Shared/IHM.h"
#include "Shared/Game.h"
#include "Shared/Player/PlayerHuman.h"
#include "Shared/Player/PlayerRobot.h"
#include "GameTaquin/Taquin.h"
#include "GameSokoban/Sokoban.h"
#include "Game2048/Game2048.h"
#include "Game2048/Game2048Variante1.h"
#include "Game2048/Game2048Variante2.h"
#include "Game2048/Game2048Variante3.h"
#include "Game2048/Game2048Variante4.h"
#include "Game2048/Game2048VarianteAll.h"

using namespace std;
using namespace sf;

int main(int argc, char** argv)
{
  // init random
  srand(time(NULL));

  if(argc < 2)
  {
    cerr << "Usage: make run jeu=[taquin|sobokan|2048|2048-variante[1-4]|2048-allvariante] joueur=[humain|robot] grille=[2-22]" << endl;
    exit(1);
  }

  int size= atoi(argv[3]);
  if(size < 2 || size > 200)
  {
    cerr << "parram: grille invalide" << endl;
    cerr << "grille=[2-22]" << endl;
    return EXIT_FAILURE;
  }

  Player* player;
  if(std::strcmp(argv[2], "humain") == 0)
    player= new PlayerHuman("Lois l'Humain");
  else if(std::strcmp(argv[2], "robot") == 0)
    player= new PlayerRobot("Jean le Robot");
  else
  {
      cerr << "parram: Joueur invalide" << endl;
      cerr << "joueur=[humain|robot]" << endl;
      return EXIT_FAILURE;
  }

  Game* game;
  if(std::strcmp(argv[1], "taquin") == 0)
    game= new Taquin("Taquin", size, *player);
  else if(std::strcmp(argv[1], "sobokan") == 0)
    game= new Sokoban("Sokoban", size, *player);
  else if(std::strcmp(argv[1], "2048") == 0)
    game= new Game2048("2048 original", size, *player);
  else if(std::strcmp(argv[1], "2048-variante1") == 0)
    game= new Game2048Variante1("2048 Variante 1", size, *player);
  else if(std::strcmp(argv[1], "2048-variante2") == 0)
    game= new Game2048Variante2("2048 Variante 2", size, *player);
  else if(std::strcmp(argv[1], "2048-variante3") == 0)
    game= new Game2048Variante3("2048 Variante 3", size, *player);
  else if(std::strcmp(argv[1], "2048-variante4") == 0)
    game= new Game2048Variante4("2048 Variante 4", size, *player);
  else if(std::strcmp(argv[1], "2048-allvariante") == 0)
    game= new Game2048VarianteAll("2048 Variante All", size, *player);
  else
  {
    cerr << "parram: Jeu invalide" << endl;
    cerr << "jeu=[taquin|sobokan|2048|2048-variante[1-4]|2048-allvariante]" << endl;
    delete player;
    return EXIT_FAILURE;
  }

  try
  {
    IHM render(600, "Projet :: Langages a objets avances M1 :: Joaquim Lefranc et Jerome Skoda");

    Event event;
    while(render.app()->isOpen())
    {
      bool newEvent= render.app()->pollEvent(event);
      game->action( newEvent, event);

      if(newEvent && (event.type == Event::Closed))
        return 0;
      else if(newEvent && (event.type == Event::KeyPressed)){
        switch(event.key.code)
        {
          case Keyboard::R:
            delete game;
            if(std::strcmp(argv[1], "taquin") == 0)
              game= new Taquin("Taquin", size, *player);
            else if(std::strcmp(argv[1], "sobokan") == 0)
              game= new Sokoban("Sokoban", size, *player);
            else if(std::strcmp(argv[1], "2048") == 0)
              game= new Game2048("2048 original", size, *player);
            else if(std::strcmp(argv[1], "2048-variante1") == 0)
              game= new Game2048Variante1("2048 Variante 1", size, *player);
            else if(std::strcmp(argv[1], "2048-variante2") == 0)
              game= new Game2048Variante2("2048 Variante 2", size, *player);
            else if(std::strcmp(argv[1], "2048-variante3") == 0)
              game= new Game2048Variante3("2048 Variante 3", size, *player);
            else if(std::strcmp(argv[1], "2048-variante4") == 0)
              game= new Game2048Variante4("2048 Variante 4", size, *player);
            else if(std::strcmp(argv[1], "2048-allvariante") == 0)
              game= new Game2048VarianteAll("2048 Variante All", size, *player);
            else
            {
              cerr << "parram: Jeu invalide" << endl;
              cerr << "jeu=[taquin|sobokan|2048|2048-variante[1-4]|2048-allvariante]" << endl;
              delete player;
              return EXIT_FAILURE;
            }
            break;

          default:
            break;

        }
      }

      game->draw(render);
      sleep(milliseconds(20));
    }
  }
  catch (std::exception const &exc)
  {
    std::cerr << "Exception caught " << exc.what() << "\n";
  }
  catch (const char* msg)
  {
    cerr << msg << endl;
  }
  catch (...)
  {
    std::cerr << "Unknown exception caught\n";
  }
  return EXIT_SUCCESS;
}
