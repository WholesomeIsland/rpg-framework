#pragma once
#include "../entities/party.hpp"
#include "../battle/Encounter.hpp"
#include <memory>
// world class manages global game state
class World {
public:
    World() = default;
    ~World() = default;
    Party currentParty;
    std::weak_ptr<Encounter> currentEncounter;
    bool inEncounter;
    void render();
    void startEncounter(std::weak_ptr<Encounter> enc);
};