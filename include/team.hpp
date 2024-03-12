#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "Attacker.hpp"
#include "Base.hpp"

class Team {
  private:
    std::list<std::shared_ptr<Attacker>> attackers;
    std::shared_ptr<Base> base;
    int money;
    bool side;

  public:
    Team(bool side);
    std::shared_ptr<Attacker> first_attacker();
    std::shared_ptr<Base> get_base();
    bool empty();
    void draw(sf::RenderWindow*);
    void move(std::shared_ptr<Attacker> first_enemy, std::shared_ptr<Base> enemy_base);
    bool add_attacker(std::shared_ptr<Attacker>);
};
