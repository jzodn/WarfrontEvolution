#pragma once

#include <SFML/Graphics.hpp>

class Attacker {
  public:
    sf::RectangleShape sprite;
    sf::FloatRect boundingBox;
    int value;

  private:
    int health;
    int damage;

  public:
    virtual void move(std::shared_ptr<Attacker> firstEnemy, std::shared_ptr<Attacker> nextAlly);
    virtual void attack(std::shared_ptr<Attacker> firstEnemy);
    virtual void take_damage(int damage);
};
