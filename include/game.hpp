#pragma once

#include <SFML/Graphics.hpp>

class Game {
	sf::RenderWindow* window;
	sf::Font* font;

	void set_values();
	void loop_events();
	void update();
	void render();

public:
	Game();
	~Game();
	void run_game();
};
