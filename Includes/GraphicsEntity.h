#pragma once
#include <SFML/Graphics.hpp>
#include "../Includes/GraphicsEntity.h"

class GraphicsEntity
{
public:
    GraphicsEntity(const float x, const float y);
    void draw(sf::RenderTarget* target);
    void set_sprite(sf::Sprite* sprite);
    void set_position(const float x = 0, const float y = 0);
    void set_size(const unsigned int width, const unsigned int height);
    void scale(const float x, const float y);
    void translate(const float x, const float y);
private:
    sf::Sprite* m_sprite;
    sf::Transform m_transform;
};