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
    std::shared_ptr<Attacker> get_first_attacker();
    std::shared_ptr<Base> get_base();
    bool empty();
    void draw(sf::RenderWindow*);
    void move(std::shared_ptr<Team> enemy_team);
    bool add_attacker(std::shared_ptr<Attacker>);
    void attack(std::shared_ptr<Team> enemy_team);
    void remove_first();
};
