#include "world.hpp"

World::World(){}

void World::render(sf::RenderWindow window){
    if(inEncounter){
        currentEncounter->draw(window);
        return;
    }
    
}