#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

Vector2f& Entity::getPos()
{
    return pos;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

void Entity::setX(float p_x)
{
    pos.x = p_x;
}

void Entity::setY(float p_y)
{
    pos.y = p_y;
}

void Entity::setPos(Vector2f p_pos)
{
    pos = p_pos;
}