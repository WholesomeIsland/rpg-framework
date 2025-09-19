#include <SFML/Graphics/RenderWindow.hpp>
#include "../world/world.hpp"
float playerSpeed = 30.f;
int main(){
    sf::RenderWindow mainWindow(sf::VideoMode({900, 540}), "Main Window");
    World mainWorld = World();
    Character* mainChar = new Character();
    mainChar->sprite = new Sprite("player/player.png");
    mainChar->sprite->addAnimation("idle", sf::Vector2i(1, 3), sf::Vector2i(32, 32), sf::Vector2i(0, 0), 60, sf::Vector2i(0, 0));
    mainChar->sprite->setAnimation("idle");
    mainChar->sprite->animationManager.update("idle", mainChar->sprite->sprite);
    mainWorld.currentParty = new Party();
    mainWorld.currentParty->party[0] = mainChar;
    mainWorld.LoadMap("backgrounds/test-map.png");
    auto previousTime = std::chrono::steady_clock::now();
    while(mainWindow.isOpen()){
        auto currentTime = std::chrono::steady_clock::now();
        auto elapsed = currentTime - previousTime;
        previousTime = currentTime;
        mainWindow.clear(sf::Color::Black);
        while(const std::optional event = mainWindow.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                mainWindow.close();
            }
        }
        float dt = std::chrono::duration<float>(elapsed).count();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
                mainChar->sprite->move({0, -1 * dt * playerSpeed});
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                mainChar->sprite->move({-1 * dt * playerSpeed, 0});
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
                mainChar->sprite->move({0, 1 * dt * playerSpeed});
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                mainChar->sprite->move({1 * dt * playerSpeed, 0});
            }
        mainWorld.render(mainWindow);
        mainWindow.display();
    }
}