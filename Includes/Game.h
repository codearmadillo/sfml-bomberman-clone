#pragma once
#include "Spritemap.h"
#include "Tile.h"
#include "vector"
#include "SFML/Graphics.hpp"

class Game
{
public:
    /** Configuration */
    static const int BLOCK_SIZE = 38;
    static const int BRICK_COVERAGE = 90;
    static const int WINDOW_WIDTH = Game::BLOCK_SIZE * 25;
    static const int WINDOW_HEIGHT = Game::BLOCK_SIZE * 17;
    static const int CAMERA_SPEED = 10;
    /** World sizes */
    static int WORLD_SIZE;
    static int WORLD_SIZES[3][2];
    /** Objects */
    static sf::Clock* deltaClock;
    static sf::RenderWindow* window;
    static SpriteMap* sprite_map;
    static std::vector<std::vector<Tile>> tile_map;
    /** Game state */

    /** Callbacks */
    static void load();
    static void run();
    /** Helper callbacks */
    static void create_window(const int width, const int height, const char* title);
    static void create_world(int size[2]);
    static void create_assets();
    static void update_world(float dt);
    static void render_world();
};