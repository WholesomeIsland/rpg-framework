#include "world.hpp"

World::World()
    : worldMapTex(new sf::Texture())
    , worldMap(*worldMapTex)
{
}

void World::render(sf::RenderWindow window){
    if(inEncounter){
        currentEncounter->draw(window);
        return;
    }
    window.draw(worldMap);
    window.draw(currentParty->party[0].sprite);
}