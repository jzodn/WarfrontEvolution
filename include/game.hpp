#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "team.hpp"

class Game {
	sf::RenderWindow* window;
	sf::Font* font;

  std::shared_ptr<Team> ally_team;
  std::shared_ptr<Team> enemy_team;

	void set_values();
	void loop_events();
	void update();
	void render();

public:
	Game();
	~Game();
	void run_game();
};
