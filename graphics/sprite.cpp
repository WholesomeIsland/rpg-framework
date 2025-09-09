#include "sprite.hpp"

Sprite::Sprite(std::string spriteSheetFile) : texture(spriteSheetFile), sprite(texture) {
}
void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    animationManager.update(currentAnimation, sprite);
    states.transform *= getTransform();
    target.draw(sprite, states);
}
void Sprite::addAnimation(std::string animation, sf::Texture texture,
   sf::Vector2i sheetSize, sf::Vector2i spriteSize, sf::Vector2i index,
   int frequency, sf::Vector2i startingIndex) {
    animationManager.addAnimation(animation, texture, sheetSize, spriteSize, index, frequency, startingIndex);
}