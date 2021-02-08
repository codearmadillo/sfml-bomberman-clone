#pragma once
#include "TileType.h"
#include "GraphicsEntity.h"
#include "Spritemap.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Tile : public GraphicsEntity
{
private:
    TileType type;
    int x;
    int y;
    SpriteMap* spritemap;
    sf::Sprite* sprite;
    sf::RectangleShape shape;
    void update_shape();
public:
    Tile(const int x, const int y, SpriteMap* spritemap);
    void render(sf::RenderWindow* window);
    void update(float dt);
    void set_type(TileType type);
};