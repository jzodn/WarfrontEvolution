#pragma once

#include "SFML/Graphics/Rect.hpp"
#include <SFML/Graphics.hpp>

class Attacker {
  private:
    sf::RectangleShape sprite;
    sf::FloatRect boundingBox;
    int value;
    bool side;
    int health;
    int damage;

  public:
    virtual void move(std::shared_ptr<Attacker> firstEnemy, std::shared_ptr<Attacker> nextAlly) = 0;
    virtual void attack(std::shared_ptr<Attacker> firstEnemy) = 0;
    virtual void take_damage(int damage) = 0;
    virtual sf::RectangleShape get_sprite() = 0;
    virtual bool intersects(sf::FloatRect) = 0;
};
