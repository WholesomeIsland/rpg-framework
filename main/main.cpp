#include <SFML/Graphics/RenderWindow.hpp>
#include "../world/world.hpp"

int main(){
    sf::RenderWindow mainWindow(sf::VideoMode({960, 540}), "Main Window");
    World mainWorld = World();
    Character* mainChar = new Character();
    mainChar->sprite = new Sprite("player/player.png");

    mainWorld.LoadMap("backgrounds/test-map.png");
    while(mainWindow.isOpen()){
        while(const std::optional event = mainWindow.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                mainWindow.close();
            }
        }
        mainWorld.render(mainWindow);
        mainWindow.display();
    }
}