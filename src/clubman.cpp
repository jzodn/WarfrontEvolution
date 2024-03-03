#include "Attacker.hpp"
#include <memory>
#include "Clubman.hpp"

Clubman::Clubman(bool side) {
  sprite.setSize(sf::Vector2f(50.f, 250.f));
  value = 10;
  health = 20;
  damage = 10;
  this->side = side;

  sprite.setPosition(side? 200.f : 1720.f, 800.f);
  boundingBox = sprite.getGlobalBounds();
}

void Clubman::move(std::shared_ptr<Attacker> firstEnemy, std::shared_ptr<Attacker> nextAlly) {
  if ((nextAlly == NULL || !nextAlly->intersects(boundingBox)) &&
        (firstEnemy == NULL || !firstEnemy->intersects(boundingBox))) {
        sprite.move(side? 1.f : -1.f, 0.f);
        boundingBox = sprite.getGlobalBounds();
  }
}

void Clubman::attack(std::shared_ptr<Attacker> firstEnemy) {
  firstEnemy->take_damage(damage);
}

void Clubman::take_damage(int damage) {
  health -= damage;
}

sf::RectangleShape Clubman::get_sprite() {
  return sprite;
}

bool Clubman::intersects(sf::FloatRect boundingBox) {
  return this->boundingBox.intersects(boundingBox);
}
