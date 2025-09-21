#include "game.hpp"
float playerSpeed = 30.f;
int main(){
    sf::RenderWindow mainWindow(sf::VideoMode({900, 540}), "Main Window");
    auto previousTime = std::chrono::steady_clock::now();
    Game game;
    while(mainWindow.isOpen()){
        while (auto event = mainWindow.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                mainWindow.close();
        }
        game.tick(mainWindow, std::chrono::duration<float>(std::chrono::steady_clock::now() - previousTime).count());
        previousTime = std::chrono::steady_clock::now();
    }
}