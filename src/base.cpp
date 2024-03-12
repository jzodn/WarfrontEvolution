#include "Base.hpp"
#include "SFML/Graphics/Rect.hpp"

Base::Base(bool side) {
  sprite.setSize(sf::Vector2f(100.f, 550.f));
  sprite.setFillColor(side ? sf::Color::White : sf::Color::Red);
  sprite.setPosition(side ? 0.f : 1820.f, 600.f);
  bounding_box = sprite.getGlobalBounds();

  health = 1000;
}

sf::RectangleShape Base::get_sprite() {
  return sprite;
}

void Base::take_damage(int damage) {
  health -= damage;
}

bool Base::intersects(sf::FloatRect bounding_box) {
  return this->bounding_box.intersects(bounding_box);
}
