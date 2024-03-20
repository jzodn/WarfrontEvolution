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
    void attack(std::shared_ptr<Team> enemy_team);
    void remove_first();
    
    template<typename T>
    bool add_attacker() {
      static_assert(std::is_base_of<Attacker, T>::value, "T must be derived from Attacker");

      if (attackers.size() < 5) {
        attackers.push_back(std::make_shared<T>(side));
        return true;
      }

      return false;
    }
};
