#pragma once

#include <SFML/Graphics.hpp>
#include "Attacker.hpp"
#include "Base.hpp"

class Clubman : public Attacker {
  private:
    sf::RectangleShape sprite;
    sf::FloatRect bounding_box;
    int value;
    bool side;
    int health;
    int damage;

  public:
    Clubman(bool side);
    void move(std::shared_ptr<Attacker> first_enemy, std::shared_ptr<Attacker> next_ally, std::shared_ptr<Base> base);
    void attack(std::shared_ptr<Attacker> first_enemy);
    void take_damage(int damage);
    sf::RectangleShape get_sprite();
    bool intersects(sf::FloatRect);
};
