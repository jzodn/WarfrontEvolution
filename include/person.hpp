#pragma once

#include <SFML/Graphics.hpp>

class Person {
  public:
    sf::RectangleShape sprite;
    sf::FloatRect boundingBox;
    bool friendly;

  private:
    int health;
    int damage;

  public:
    virtual void move();
    virtual void attack(Person person);
    virtual void take_damge();
};
