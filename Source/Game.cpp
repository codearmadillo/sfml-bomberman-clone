#include "../Includes/Game.h"
#include "../Includes/Spritemap.h"
#include "../Includes/Tile.h"
#include "SFML/Graphics.hpp"
#include "vector"

/** Initializers */
int Game::WORLD_SIZE = 0;
int Game::WORLD_SIZES[3][2] = { {25, 17}, {49, 33}, {71, 47} };
sf::RenderWindow* Game::window = nullptr;
sf::Clock* Game::deltaClock = nullptr;
SpriteMap* Game::sprite_map = nullptr;
std::vector<std::vector<Tile>> Game::tile_map = std::vector<std::vector<Tile>>();

/** Callbacks */
void Game::load()
{
    /** Create new clock instance */
    Game::deltaClock = new sf::Clock();
    /** Set random seed */
    std::srand(std::time(nullptr));
    /** Create game */
    Game::create_window(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT, "Bomberman");
    Game::create_assets();
    Game::create_world(Game::WORLD_SIZES[Game::WORLD_SIZE]);
}
void Game::run()
{
    while (Game::window->isOpen())
    {
        /** Get delta */
        sf::Time delta = Game::deltaClock->restart();
        /** Process events */
        sf::Event event;
        while (Game::window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                Game::window->close();
        }
        /** Clear window */
        Game::window->clear();
        /** Update and render */
        Game::update_world(delta.asSeconds());
        Game::render_world();
        /** Display */
        Game::window->display();
    }
}
void Game::create_window(const int width, const int height, const char* title)
{
    Game::window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}
void Game::create_world(int size[2])
{
    for(int y = 0; y < Game::WORLD_SIZES[Game::WORLD_SIZE][1]; ++y)
    {
        Game::tile_map.emplace_back();
        for(int x = 0; x < Game::WORLD_SIZES[Game::WORLD_SIZE][0]; ++x)
        {
            // Default tile
            Tile t(x, y, Game::sprite_map);
            // Determine type
            if(y == 0 || x == 0 || y == Game::WORLD_SIZES[Game::WORLD_SIZE][1] - 1 || x == Game::WORLD_SIZES[Game::WORLD_SIZE][0] - 1)
            {
                t.set_type(TILE_WALL);
            }
            else
            {
                if(x > 1 & y > 1 && x < Game::WORLD_SIZES[Game::WORLD_SIZE][0] - 2 && y < Game::WORLD_SIZES[Game::WORLD_SIZE][1] - 2)
                {
                    if((x - 2) % 2 == 0 && (y - 2) % 2 == 0)
                    {
                        t.set_type(TILE_WALL);
                    }
                }
            }
            // Push
            Game::tile_map[y].push_back(t);
        }
    }
}
void Game::create_assets()
{
    Game::sprite_map = new SpriteMap("Resources/tilemap.png", 3, 2, Game::BLOCK_SIZE, Game::BLOCK_SIZE);
}

void Game::update_world(float dt)
{
    /** Tiles */
    for(int y = 0; y < Game::WORLD_SIZES[Game::WORLD_SIZE][1]; ++y)
    {
        for(int x = 0; x < Game::WORLD_SIZES[Game::WORLD_SIZE][0]; ++x)
        {
            Game::tile_map[y][x].update(dt);
        }
    }
}
void Game::render_world()
{
    /** Tiles */
    for(int y = 0; y < Game::WORLD_SIZES[Game::WORLD_SIZE][1]; ++y)
    {
        for(int x = 0; x < Game::WORLD_SIZES[Game::WORLD_SIZE][0]; ++x)
        {
            Game::tile_map[y][x].render(Game::window);
        }
    }
}