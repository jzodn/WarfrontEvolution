#pragma once

#include <SFML/Graphics.hpp>
#include "person.hpp"

class Clubman : public Person {
  public:
    sf::RectangleShape sprite;
    sf::FloatRect boundingBox;
    bool friendly;

  private:
    int health;
    int damage;

  public:
    Clubman(bool friendly);
    ~Clubman();
    void move();
    void attack(Person person);
    void take_damage();
};
