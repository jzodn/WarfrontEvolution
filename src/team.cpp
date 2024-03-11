#include "Team.hpp"
#include <memory>

Team::Team() {
  this->money = 0;
}

std::shared_ptr<Attacker> Team::first_attacker() {
  return attackers.front();
}

bool Team::empty() {
  return attackers.empty();
}

void Team::draw(sf::RenderWindow* window) {
  for (auto attacker : attackers) {
    window->draw(attacker->get_sprite());
  }
}

void Team::move(std::shared_ptr<Attacker> first_enemy) {
  std::shared_ptr<Attacker> next_ally = NULL;

  for (auto attacker : attackers) {
    attacker->move(first_enemy, next_ally);
    next_ally = attacker;
  } 
}

bool Team::add_attacker(std::shared_ptr<Attacker> attacker) {
  if (attackers.size() < 5) {
    attackers.push_back(attacker);
    return true;
  }

  return false;
}
