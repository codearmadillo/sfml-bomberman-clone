#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class SpriteMap
{
public:
    SpriteMap(const char* file, const int cols, const int rows);
    SpriteMap(const char* file, const int cols, const int rows, const float tile_width, const float tile_height);
    sf::Sprite* get_sprite(const int col, const int row);
    sf::Vector2<float> getTileSize();
private:
    int m_cols;
    int m_rows;
    float m_tile_width = -1.0f;
    float m_tile_height = -1.0f;
    const char* m_file;
    sf::Vector2<float> m_tile_size;
    bool m_file_loaded = false;
    sf::Texture m_texture;
    std::vector<std::vector<sf::Sprite*>> m_tiles;
    void load_image(const char* file);
    void parse_texture();
    void load_spritemap();
    bool is_spritemap_resized() const;
};