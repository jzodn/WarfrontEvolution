#include <SFML/Graphics.hpp>
#include "menu.hpp"
#include "game.hpp"


int main() {
  Menu* menu = new Menu();
  menu->run_menu();

  if (menu->get_pos() == 1) {
    delete menu;

    Game* game = new Game();
    game->run_game();
    
    delete game;
  } else {
    delete menu;
  }

  return 0;
}
