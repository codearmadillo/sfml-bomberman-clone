#include "../Includes/Tile.h"
#include "../Includes/TileType.h"
#include "../Includes/Game.h"
#include "../Includes/Spritemap.h"

Tile::Tile(const int x, const int y, SpriteMap* spritemap) : GraphicsEntity(x, y)
{
    this->type = TILE_EMPTY;
    this->x = x;
    this->y = y;
    this->spritemap = spritemap;
    this->sprite = nullptr;
    /** Set shape */
    this->shape = sf::RectangleShape();
    /** Set position */
    this->set_size(BLOCK_SIZE, BLOCK_SIZE);
    this->set_position(
        BLOCK_SIZE * this->x, BLOCK_SIZE * this->y
    );
    /** Update shape */
    this->update_shape();
}
void Tile::render(sf::RenderWindow* window)
{
    this->draw(window);
}
void Tile::update(float dt)
{

}
void Tile::set_type(TileType type)
{
    this->type = type;
    this->update_shape();
}
void Tile::update_shape()
{
    switch(this->type)
    {
        case TILE_WALL:
            this->set_sprite(this->spritemap->get_sprite(0, 0 ));
            break;
        case TILE_BRICK:
            this->set_sprite(this->spritemap->get_sprite(1, 0 ));
            break;
        case TILE_EMPTY:
            this->set_sprite(this->spritemap->get_sprite(2, 0 ));
            break;
    }
}