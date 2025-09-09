#pragma once
#include <SFML/Graphics.hpp>

class Background : public sf::Drawable, public sf::Transformable {
public:
    sf::Texture texture;
    sf::Sprite sprite;

    Background(const std::string& textureFile);
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};