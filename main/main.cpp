#include "game.hpp"
int main(){
    sf::RenderWindow mainWindow(sf::VideoMode({900, 540}), "rpg-framwork");
    sf::Clock clock;
    Game game;
    
    sf::Time prevTime = clock.getElapsedTime();
    while(mainWindow.isOpen()){
        while (auto event = mainWindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                mainWindow.close();
        }
        sf::Time currentTime = clock.getElapsedTime();
        sf::Time timestep = currentTime - prevTime;
        game.tick(mainWindow, timestep.asSeconds());

        prevTime = currentTime;
    }
}