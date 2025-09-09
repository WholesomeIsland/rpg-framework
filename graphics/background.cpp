#include "background.hpp"

Background::Background(const std::string& textureFile) : texture(textureFile), sprite(texture) {
}
void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(sprite, states);
}