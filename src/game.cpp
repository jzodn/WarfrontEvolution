#include "Game.hpp"
#include "clubman.hpp"
#include <memory>

Game::Game() {
  window = new sf::RenderWindow();
  font = new sf::Font();

  set_values();
}

Game::~Game() {
  delete window;
  delete font;
}

void Game::set_values() {
  window->create(sf::VideoMode(1920, 1080), "Warfront Evolution - Game");
  window->setFramerateLimit(144);

  if (!font->loadFromFile("arial.ttf")) {
      printf("error");
  }

  ally_team = std::make_shared<Team>(true);
  enemy_team = std::make_shared<Team>(false);

  // TODO: change this to just pass the type of attacker
  ally_team->add_attacker(std::make_shared<Clubman>(true));
  // ally_team.add_attacker(std::make_shared<Clubman>(true));
  enemy_team->add_attacker(std::make_shared<Clubman>(false));
}

void Game::loop_events() {
  sf::Event event;

  while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
          window->close();
      }
  }
}

void Game::update() {
  ally_team->move(enemy_team);
  enemy_team->move(ally_team);

  ally_team->attack(enemy_team);
  enemy_team->attack(ally_team);
}

void Game::render() {
  window->clear();

  ally_team->draw(window);
  enemy_team->draw(window);

  window->display();
}

void Game::run_game() {
  sf::Clock clock;

  while (window->isOpen()) {
    sf::Time elapsed = clock .restart();

    loop_events();
    update();
    render();
  }
}
