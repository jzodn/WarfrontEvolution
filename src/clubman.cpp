#include "Attacker.hpp"
#include <memory>
#include "Clubman.hpp"

Clubman::Clubman() {
  sprite.setSize(sf::Vector2f(50.f, 250.f));
  boundingBox = sprite.getGlobalBounds();
  value = 10;
  health = 20;
  damage = 10;
}

void Clubman::move(std::shared_ptr<Attacker> firstEnemy, std::shared_ptr<Attacker> nextAlly) {
  if ((nextAlly == NULL || !boundingBox.intersects(nextAlly->boundingBox) &&
        (firstEnemy == NULL || !boundingBox.intersects(firstEnemy->boundingBox)))) {
        sprite.move(1.f, 0.f);
        boundingBox = sprite.getGlobalBounds();
      }
}

void Clubman::attack(std::shared_ptr<Attacker> firstEnemy) {
  firstEnemy->take_damage(damage);
}

void Clubman::take_damage(int damage) {
  health -= damage;
}
