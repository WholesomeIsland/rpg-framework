#pragma once
#include "../entities/party.hpp"
#include "../entities/enemy.hpp"
#include <vector>

struct Encounter {
    Party player;
    std::vector<Enemy> enemies;
};
