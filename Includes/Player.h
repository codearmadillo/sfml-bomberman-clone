#pragma once
#include <SFML/Window/Keyboard.hpp>

struct PlayerControls
{
    sf::Keyboard::Key up;
    sf::Keyboard::Key down;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Keyboard::Key bomb;
};

class Player {
public:
    Player(const float x, const float y, PlayerControls controls);
    void render();
    void update(float dt);
private:
    float m_x;
    float m_y;
    float m_speed;
    PlayerControls m_controls;
};