#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "Attacker.hpp"

class Team {
  private:
    std::list<std::shared_ptr<Attacker>> attackers;
    int money;

  public:
    Team();
    std::shared_ptr<Attacker> first_attacker();
    bool empty();
    void draw(sf::RenderWindow*);
    void move(std::shared_ptr<Attacker> first_enemy);
    bool add_attacker(std::shared_ptr<Attacker>);
};
