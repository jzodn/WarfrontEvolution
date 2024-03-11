#pragma once

#include <SFML/Graphics.hpp>
#include "team.hpp"

class Game {
	sf::RenderWindow* window;
	sf::Font* font;

  Team ally_team;
  Team enemy_team;

	void set_values();
	void loop_events();
	void update();
	void render();

public:
	Game();
	~Game();
	void run_game();
};
