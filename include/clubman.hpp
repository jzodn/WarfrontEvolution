#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Attacker.hpp"

class Clubman : public Attacker {
  public:
    sf::RectangleShape sprite;
    sf::FloatRect boundingBox;
    int value;

  private:
    int health;
    int damage;

  public:
    Clubman();
    void move(std::shared_ptr<Attacker> firstEnemy, std::shared_ptr<Attacker> nextAlly);
    void attack(std::shared_ptr<Attacker> firstEnemy);
    void take_damage(int damage);
};
