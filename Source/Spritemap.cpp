#include "../Includes/Spritemap.h"
#include <SFML/Graphics.hpp>

SpriteMap::SpriteMap(const char* file, const int cols, const int rows)
{
    this->m_rows = rows;
    this->m_cols = cols;
    this->m_file = file;
    /** Load */
    this->load_spritemap();
}
SpriteMap::SpriteMap(const char* file, const int cols, const int rows, const float tile_width, const float tile_height)
{
    this->m_rows = rows;
    this->m_cols = cols;
    this->m_file = file;
    this->m_tile_width = tile_width;
    this->m_tile_height = tile_height;
    /** Load */
    this->load_spritemap();
}
sf::Sprite* SpriteMap::get_sprite(const int col, const int row)
{
    if(!this->m_file_loaded)
        return nullptr;
    if(col > this->m_cols - 1 || row > this->m_rows - 1)
        return nullptr;
    return this->m_tiles[row][col];
}
void SpriteMap::load_spritemap()
{
    this->load_image(this->m_file);
    this->parse_texture();
}
void SpriteMap::load_image(const char* file)
{
    /** Create texture */
    this->m_texture = sf::Texture();
    if(this->m_texture.loadFromFile(file))
    {
        this->m_file_loaded = true;
    }
}
sf::Vector2<float> SpriteMap::getTileSize()
{
    return this->m_tile_size;
}
void SpriteMap::parse_texture()
{
    if(!this->m_file_loaded)
        return;
    /** Get block size */
    sf::Vector2<unsigned int> image_size = this->m_texture.getSize();
    this->m_tile_size = { (float)(image_size.x / this->m_cols), (float)(image_size.y / this->m_rows) };
    /** Set scale factor if any */
    sf::Vector2<float> scale_factor;
    if(this->is_spritemap_resized())
    {
        scale_factor = sf::Vector2<float>((float)(this->m_tile_width/this->m_tile_size.x), (float)(this->m_tile_height/this->m_tile_size.y));
    }
    /** Iterate through image */
    for(int y = 0; y < this->m_rows; ++y)
    {
        m_tiles.push_back(std::vector<sf::Sprite*>());
        for(int x = 0; x < this->m_cols; ++x)
        {
            sf::Sprite* sprite = new sf::Sprite();
            /** Set correct sub image */
            sprite->setTexture(this->m_texture);
            sprite->setTextureRect(sf::IntRect(
                    this->m_tile_size.x * x,
                    this->m_tile_size.y * y,
                    this->m_tile_size.x,
                    this->m_tile_size.y
            ));
            /** Resize */
            if(this->is_spritemap_resized())
            {
                sprite->setScale(scale_factor.x, scale_factor.y);
            }
            /** Push to map */
            m_tiles[y].push_back(sprite);
        }
    }
}
bool SpriteMap::is_spritemap_resized() const
{
    return this->m_tile_width != -1.0f && this->m_tile_height != -1.0f;
}