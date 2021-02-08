#include "../Includes/Player.h"

Player::Player(const float x, const float y, PlayerControls controls)
{
    this->m_x = x;
    this->m_y = y;
    this->m_speed = 10.0f;
    this->m_controls = controls;
}
void Player::render()
{

}
void Player::update(float dt)
{

}