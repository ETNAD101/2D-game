#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Player.hpp"
#include "Math.hpp"

Player::Player(Vector2f p_pos, SDL_Texture* p_tex)
	:Entity{p_pos, p_tex}, velocity(0, 0)
{

}

void Player::move(Vector2f p_vel)
{
	Vector2f currentPos = this->getPos();
	currentPos.x += p_vel.x;
	currentPos.y += p_vel.y;

	this->setX(currentPos.x);
	this->setY(currentPos.y);
}