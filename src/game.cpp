#include "Game.hpp"

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
    window->create(sf::VideoMode(1000, 600), "Pong - Game");
    window->setFramerateLimit(144);

    if (!font->loadFromFile("arial.ttf")) {
        printf("error");
    }
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
}

void Game::render() {
    window->clear();

    window->display();
}

void Game::run_game() {
    while (window->isOpen()) {
        loop_events();
        update();
        render();
    }
}
