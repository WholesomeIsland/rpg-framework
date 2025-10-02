#include "button.hpp"

Button::Button(std::string text, sf::Font font)
    : buttonRect(), text(font, text)
{

}

bool Button::Draw(sf::RenderWindow window){
    bool retval = false;
    auto mousePos = sf::Mouse::getPosition(window);
    auto rectBounds = this->buttonRect.getGlobalBounds().contains(sf::Vector2f(mousePos));
    if(rectBounds){
        isHovered = true;
    }
    if(isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        retval = true;
    }
    buttonRect.setPosition(this->getPosition());
    buttonRect.setRotation(this->getRotation());
    window.draw(buttonRect);
    text.setPosition(this->getPosition() + textOffset);
    text.setRotation(this->getRotation());
    window.draw(text);
    return retval;
}