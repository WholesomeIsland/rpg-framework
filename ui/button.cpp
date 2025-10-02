#include "button.hpp"
#include "../globals/gmath.hpp"

Button::Button(std::string text, sf::Font font)
    : buttonRect(), text(font, text)
{
    buttonRect.setSize(sf::Vector2f(10.0f,10.0f));
}

bool Button::Draw(sf::RenderWindow& window){
    bool retval = false;
    auto mousePos = sf::Mouse::getPosition(window);
    auto rectBounds = this->buttonRect.getGlobalBounds().contains(sf::Vector2f(mousePos));
    if(rectBounds){
        isHovered = true;
        buttonRect.setFillColor(mixColors(rectColor, hoverTint));
        text.setFillColor(mixColors(textColor, hoverTint));
    }
    if(isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        retval = true;
    }
    if(isHovered && retval){
        buttonRect.setFillColor(mixColors(rectColor, clickTint));
        text.setFillColor(mixColors(textColor, clickTint));
    }
    if(!isHovered && !retval){
        buttonRect.setFillColor(rectColor);
        text.setFillColor(textColor);
    }
    buttonRect.setPosition(this->getPosition());
    buttonRect.setRotation(this->getRotation());
    window.draw(buttonRect);
    text.setPosition(this->getPosition() + textOffset);
    text.setRotation(this->getRotation());
    window.draw(text);
    return retval;
}