#include "Includes/Game.h"

int main(void)
{
    /** Load game */
    Game::load();
    /** Run loop */
    Game::run();
    /** And.. exit.. */
    return EXIT_SUCCESS;
}

void add_camera()
{
    /*
    camera = new sf::View();
    camera->reset({0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && camera->getViewport().left > 0)
    {
        camera->move({-CAMERA_SPEED * dt, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && camera->getViewport().left + camera->getViewport().width < WORLD_SIZES[WORLD_SIZE][0] * BLOCK_SIZE)
    {
        camera->move({CAMERA_SPEED * dt, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && camera->getViewport().top > 0)
    {
        camera->move({0, -CAMERA_SPEED * dt});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && camera->getViewport().top + camera->getViewport().height < WORLD_SIZES[WORLD_SIZE][1] * BLOCK_SIZE)
    {
        camera->move({0, CAMERA_SPEED * dt});
    }
    window->setView(*camera);
    */
}