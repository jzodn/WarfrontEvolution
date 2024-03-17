#include "Team.hpp"
#include <memory>
#include <iostream>

Team::Team(bool side) {
  base = std::make_shared<Base>(side); 
  this->money = 0;
}

std::shared_ptr<Attacker> Team::get_first_attacker() {
  if (attackers.empty()) {
    return NULL;
  }

  return attackers.front();
}

bool Team::empty() {
  return attackers.empty();
}

void Team::draw(sf::RenderWindow* window) {
  for (auto attacker : attackers) {
    window->draw(attacker->get_sprite());
  }

  window->draw(base->get_sprite());
}

void Team::move(std::shared_ptr<Team> enemy_team) {
  std::shared_ptr<Attacker> next_ally = NULL;

  for (auto attacker : attackers) {
    attacker->move(enemy_team->get_first_attacker(), next_ally, enemy_team->get_base());
    next_ally = attacker;
  } 
}

// TODO: change this to just pass the type of attacker
bool Team::add_attacker(std::shared_ptr<Attacker> attacker) {
  if (attackers.size() < 5) {
    attackers.push_back(attacker);
    return true;
  }

  return false;
}

std::shared_ptr<Base> Team::get_base() {
  return base;
}

void Team::attack(std::shared_ptr<Team> enemy_team) {
  std::shared_ptr<Attacker> first_attacker = get_first_attacker();

  if (first_attacker == NULL) {
    return;
  }

  std::shared_ptr<Attacker> first_enemy_attacker = enemy_team->get_first_attacker();

  if (first_enemy_attacker != NULL && first_attacker->get_attack_timer() && first_enemy_attacker->intersects(first_attacker->get_bounding_box())) {
    if (first_attacker->attack(first_enemy_attacker)) {
      // TODO:
      // When enemy dies add money
      enemy_team->remove_first();
      return;
    }
  }

  std::shared_ptr<Base> enemy_base = enemy_team->get_base();

  if (first_attacker->get_attack_timer() && enemy_base->intersects(first_attacker->get_bounding_box())) {
    if (first_attacker->attack(enemy_base)) {
      // TODO: 
      // Expand this winning / lossing function
      std::cout << (!side ? "You win!" : "You lose!") << std::endl;
      return;
    }
  }
}

void Team::remove_first() {
  attackers.pop_front();
}
