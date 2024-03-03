#pragma once

#include <SFML/Graphics.hpp>
#include "Attacker.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class Clubman : public Attacker {
  private:
    sf::RectangleShape sprite;
    sf::FloatRect boundingBox;
    int value;
    bool side;
    int health;
    int damage;

  public:
    Clubman(bool side);
    void move(std::shared_ptr<Attacker> firstEnemy, std::shared_ptr<Attacker> nextAlly);
    void attack(std::shared_ptr<Attacker> firstEnemy);
    void take_damage(int damage);
    sf::RectangleShape get_sprite();
    bool intersects(sf::FloatRect);
};
