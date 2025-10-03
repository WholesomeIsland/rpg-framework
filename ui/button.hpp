#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Button : public sf::Transformable
{
public:
    Button(std::string text, sf::Font& font);
    bool Draw(sf::RenderWindow& window); // returns true if pressed
    bool isHovered;
    bool isPressed;
    sf::Vector2f textOffset;
    sf::RectangleShape buttonRect;
    sf::Text text;
    sf::Color hoverTint;
    sf::Color clickTint;
    sf::Color textColor;
    sf::Color rectColor;
};