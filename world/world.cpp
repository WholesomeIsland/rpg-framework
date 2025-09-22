#include "world.hpp"

void World::render(sf::RenderWindow& window, float dt){
    if(inEncounter){
        currentEncounter->draw(window, dt);
        return;
    }
    window.draw(*worldMap);
    window.draw(*currentParty->party[0]->sprite);
}

void World::startEncounter(Encounter* enc){
    if(enc == nullptr) return;
    this->currentEncounter = enc;
    inEncounter = true;
}

void World::LoadMap(const std::filesystem::path& path){
    enum FileType{
        png
    };
    FileType type = FileType::png;
    switch (type)
    {
    case FileType::png:
        this->worldMapTex = new sf::Texture(path.string());
        std::cout << path << std::endl;
        this->worldMap = new sf::Sprite(*this->worldMapTex);
        break;
    default:
        break;
    }
}