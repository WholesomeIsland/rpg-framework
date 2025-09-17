#pragma once
#include "../entities/party.hpp"
#include "../battle/Encounter.hpp"
#include <memory>
// world class manages global game state
class World {
public:
    World() = default;
    ~World() = default;
    Party* currentParty;
    Encounter* currentEncounter;
    sf::Texture* worldMapTex;
    sf::Sprite* worldMap;
    bool inEncounter;
    void render(sf::RenderWindow& window);
    void startEncounter(Encounter* enc);
    void LoadMap(const std::filesystem::path& filename);
    
};