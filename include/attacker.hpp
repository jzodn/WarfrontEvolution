#pragma once

#include "SFML/Graphics/Rect.hpp"
#include <SFML/Graphics.hpp>
#include "Base.hpp"

class Attacker {
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
    virtual void move(std::shared_ptr<Attacker> first_enemy, std::shared_ptr<Attacker> next_ally, std::shared_ptr<Base> base) = 0;
    virtual bool attack(std::shared_ptr<Attacker> enemy) = 0;
    virtual bool attack(std::shared_ptr<Base> enemy_base) = 0;
    virtual bool take_damage(int damage) = 0;
    virtual sf::RectangleShape get_sprite() = 0;
    virtual bool intersects(sf::FloatRect) = 0;
    virtual sf::FloatRect get_bounding_box() = 0;
    virtual bool get_attack_timer() = 0;
};
