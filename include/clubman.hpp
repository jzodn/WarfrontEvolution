#pragma once

#include <SFML/Graphics.hpp>
#include "Attacker.hpp"
#include "Base.hpp"
#include "SFML/Graphics/Rect.hpp"

class Clubman : public Attacker {
  private:
    sf::RectangleShape sprite;
    sf::FloatRect bounding_box;
    int value;
    bool side;
    int health;
    int damage;
    sf::Clock attack_timer;
    sf::Int32 attack_timer_max;

  public:
    Clubman(bool side);
    void move(std::shared_ptr<Attacker> first_enemy, std::shared_ptr<Attacker> next_ally, std::shared_ptr<Base> base);
    bool attack(std::shared_ptr<Attacker> enemy);
    bool take_damage(int damage);
    sf::RectangleShape get_sprite();
    bool intersects(sf::FloatRect);
    sf::FloatRect get_bounding_box();
    bool get_attack_timer();
};
