#include <SFML/Graphics/RenderWindow.hpp>

int main(){
    sf::RenderWindow mainWindow(sf::VideoMode({800, 600}), "Main Window");
    while(mainWindow.isOpen()){
        while(const std::optional event = mainWindow.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                mainWindow.close();
            }
        }
    }
}