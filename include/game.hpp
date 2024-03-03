#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "attacker.hpp"

class Game {
	sf::RenderWindow* window;
	sf::Font* font;

  std::list<std::shared_ptr<Attacker>> allies;
  std::list<std::shared_ptr<Attacker>> enemies;

	void set_values();
	void loop_events();
	void update();
	void render();

public:
	Game();
	~Game();
	void run_game();
};
