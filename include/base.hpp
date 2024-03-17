#pragma once

#include "SFML/Graphics/Rect.hpp"
#include <SFML/Graphics.hpp>

class Base {
  private:
    sf::RectangleShape sprite;
    sf::FloatRect bounding_box;
    int health;

  public:
    Base(bool side);
    sf::RectangleShape get_sprite();
    bool take_damage(int);
    bool intersects(sf::FloatRect);
};
