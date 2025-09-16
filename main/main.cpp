#include <SFML/Graphics/RenderWindow.hpp>
#include "../world/world.hpp"

int main(){
    sf::RenderWindow mainWindow(sf::VideoMode({800, 600}), "Main Window");
    World mainWorld = World();
    while(mainWindow.isOpen()){
        while(const std::optional event = mainWindow.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                mainWindow.close();
            }
        }
    }
}