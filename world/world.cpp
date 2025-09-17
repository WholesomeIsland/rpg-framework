#include "world.hpp"

World::World()
{
}

void World::render(sf::RenderWindow window){
    if(inEncounter){
        currentEncounter->draw(window);
        return;
    }
    window.draw(*worldMap);
    window.draw(currentParty->party[0].sprite);
}

void World::startEncounter(Encounter* enc){
    if(enc == nullptr) return;
    this->currentEncounter = enc;
    inEncounter = true;
}

void World::LoadMap(const std::filesystem::path& path){
    enum FileType{
        tiled,
        png
    };
    FileType type;
    if(path.extension() == "tmx") type = FileType::tiled;
    if(path.extension() == "png") type = FileType::png;
    switch (type)
    {
    case FileType::tiled:
        break;
    case FileType::png:
        this->worldMapTex = new sf::Texture();
        this->worldMapTex->loadFromFile(path);
        break;
    default:
        break;
    }
}