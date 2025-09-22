#pragma once

#include <SFML/Graphics.hpp>
#include "AnimationManager.hpp"

class Sprite : public sf::Drawable, public sf::Transformable {
public:
    sf::Texture texture;
    sf::Texture sheetTexture;
    mutable sf::Sprite sprite;
    mutable AnimationManager animationManager;
    std::string currentAnimation;
    mutable bool animationFinishedLastFrame = false;
    
    Sprite(std::string spriteSheetFile);
    void addAnimation(std::string animation, sf::Vector2i spritesheetSize, sf::Vector2i spriteSize, sf::Vector2i index = sf::Vector2i(0, 0),
       int frequency = 0, sf::Vector2i startingIndex = sf::Vector2i(0, 0));
    void setAnimation(std::string animation) { currentAnimation = animation; }
    std::string getCurrentAnimation() const { return currentAnimation; }
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};