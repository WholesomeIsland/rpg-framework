#include "sprite.hpp"

Sprite::Sprite(std::string spriteSheetFile) : texture(spriteSheetFile), sheetTexture(texture), sprite(texture) {
}
void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    animationManager.update(currentAnimation, sprite);
    states.transform *= getTransform();
    target.draw(sprite, states);
}
void Sprite::addAnimation(std::string animation, sf::Vector2i spritesheetSize, sf::Vector2i spriteSize, sf::Vector2i index,
   int frequency, sf::Vector2i startingIndex) {
    animationManager.addAnimation(animation, sheetTexture, spritesheetSize, spriteSize, index, frequency, startingIndex);
}