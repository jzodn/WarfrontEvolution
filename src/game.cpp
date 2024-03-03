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

    allies.push_back(std::make_shared<Clubman>(true));
    enemies.push_back(std::make_shared<Clubman>(false));
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
  allies.front()->move(enemies.empty()? NULL : enemies.front(), NULL);
  enemies.front()->move(allies.empty()? NULL : allies.front(), NULL);
}

void Game::render() {
    window->clear();

    for (auto ally : allies) {
      window->draw(ally->get_sprite());
    }

    for (auto enemy : enemies) {
      window->draw(enemy->get_sprite());
    }

    // std::shared_ptr<Attacker> cm = enemies.front();
    // window->draw(cm->sprite);
    // printf("%s", cm->side ? "True" : "False");
    // printf("%d", cm->value);

    window->display();
}

void Game::run_game() {
    while (window->isOpen()) {
        loop_events();
        update();
        render();
    }
}
