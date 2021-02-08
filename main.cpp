#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <vector>

#include "Includes/Game.h"
#include "Includes/Tile.h"

const int WORLD_SIZE = 0;
const int WORLD_SIZES[3][2] = { {25, 17}, {49, 33}, {71, 47} };

/** Globals */
sf::RenderWindow* window;
SpriteMap* spritemap;
/** Map */
std::vector<std::vector<Tile>> tiles;

void update(float dt);
void render();
void load();

int main(void)
{
    // Set seed
    std::srand(std::time(nullptr));
    // Delta clock
    sf::Clock deltaClock;
    // Load application
    load();
    // Start the game loop
    while (window->isOpen())
    {
        // Get DT
        sf::Time delta = deltaClock.restart();
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window->close();
        }
        // Clear window
        window->clear();
        // Update
        update(delta.asSeconds());
        // Render
        render();
        // Display
        window->display();
    }
    return EXIT_SUCCESS;
}
void load()
{
    /** Load spritemap */
    spritemap = new SpriteMap("Resources/tilemap.png", 3, 2, BLOCK_SIZE, BLOCK_SIZE);
    /** Create window */
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "BomberMan");
    /** Generate */
    for(int y = 0; y < WORLD_SIZES[WORLD_SIZE][1]; ++y)
    {
        tiles.push_back(std::vector<Tile>());
        for(int x = 0; x < WORLD_SIZES[WORLD_SIZE][0]; ++x)
        {
            /** Create empty tile */
            Tile tile(x, y, spritemap);
            /** Draw wall at the edges */
            if(y == 0 || x == 0 || y == WORLD_SIZES[WORLD_SIZE][1] - 1 || x == WORLD_SIZES[WORLD_SIZE][0] - 1)
            {
                tile.set_type(TILE_WALL);
            }
            else
            {
                if(x > 1 & y > 1 && x < WORLD_SIZES[WORLD_SIZE][0] - 2 && y < WORLD_SIZES[WORLD_SIZE][1] - 2)
                {
                    if((x - 2) % 2 == 0 && (y - 2) % 2 == 0)
                    {
                        tile.set_type(TILE_WALL);
                    }
                }
            }
            /** Push tile */
            tiles[y].push_back(tile);
        }
    }
}
void update(float dt)
{
    for(int y = 0; y < WORLD_SIZES[WORLD_SIZE][1]; ++y)
    {
        for(int x = 0; x < WORLD_SIZES[WORLD_SIZE][0]; ++x)
        {
            tiles[y][x].update(dt);
        }
    }
}
void render()
{
    for(int y = 0; y < WORLD_SIZES[WORLD_SIZE][1]; ++y)
    {
        for(int x = 0; x < WORLD_SIZES[WORLD_SIZE][0]; ++x)
        {
            tiles[y][x].render(window);
        }
    }
}