#include "../Includes/GraphicsEntity.h"

GraphicsEntity::GraphicsEntity(const float x, const float y)
{
    /** Set sprite */
    m_sprite = nullptr;
    /** Set transform */
    m_transform = sf::Transform();
    m_transform.translate(x, y);
}
void GraphicsEntity::draw(sf::RenderTarget* target)
{
    if(this->m_sprite == nullptr)
    {
        return;
    }
    target->draw(*this->m_sprite, this->m_transform);
}
void GraphicsEntity::set_sprite(sf::Sprite* sprite)
{
    this->m_sprite = sprite;
}
void GraphicsEntity::set_size(const unsigned int width, const unsigned int height)
{

}
void GraphicsEntity::set_position(const float x, const float y)
{
    this->m_transform = sf::Transform();
    this->m_transform.translate(x, y);
}
void GraphicsEntity::scale(const float x, const float y)
{
    this->m_transform.scale(x, y);
}
void GraphicsEntity::translate(const float x, const float y)
{
    this->m_transform.translate(x, y);
}
