#include "Attacker.hpp"
#include <memory>
#include "base.hpp"
#include "clubman.hpp"

Clubman::Clubman(bool side) {
  sprite.setSize(sf::Vector2f(50.f, 250.f));
  sprite.setFillColor(side ? sf::Color::White : sf::Color::Red);
  sprite.setPosition(side? 200.f : 1720.f, 800.f);

  value = 10;
  health = 20;
  damage = 10;
  this->side = side;
  bounding_box = sprite.getGlobalBounds();

  attack_timer.restart();
  attack_timer_max = 500;
}

void Clubman::move(std::shared_ptr<Attacker> first_enemy, std::shared_ptr<Attacker> next_ally, std::shared_ptr<Base> enemy_base) {
  if ((next_ally == NULL || !next_ally->intersects(bounding_box)) &&
        (first_enemy == NULL || !first_enemy->intersects(bounding_box)) &&
        !enemy_base->intersects(bounding_box)) {
        sprite.move(side? 1.f : -1.f, 0.f);
        bounding_box = sprite.getGlobalBounds();
  }
}

bool Clubman::attack(std::shared_ptr<Attacker> enemy) {
  return enemy->take_damage(damage);
}

bool Clubman::attack(std::shared_ptr<Base> enemy_base) {
  return enemy_base->take_damage(damage);
}

bool Clubman::take_damage(int damage) {
  health -= damage;

  return health <= 0;
}

sf::RectangleShape Clubman::get_sprite() {
  return sprite;
}

bool Clubman::intersects(sf::FloatRect bounding_box) {
  return this->bounding_box.intersects(bounding_box);
}

sf::FloatRect Clubman::get_bounding_box() {
  return bounding_box;
}

bool Clubman::get_attack_timer() {
  if(attack_timer.getElapsedTime().asMilliseconds() > attack_timer_max) {
    attack_timer.restart();
    return true;
  }

  return false;
}
