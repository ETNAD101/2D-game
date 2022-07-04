#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Player.hpp"
#include "Math.hpp"

Player::Player(Vector2f p_pos, Vector2f p_vel, SDL_Texture* p_tex)
	:Entity{p_pos, p_tex}, velocity(p_vel)
{

}

void Player::setVelocity(Vector2f p_vel)
{
	velocity = p_vel;
}

Vector2f Player::getVelocity()
{
	return velocity;
}

void Player::move(Vector2f p_vel)
{
	Vector2f currentPos = this->getPos();
	currentPos.x += p_vel.x;
	currentPos.y += p_vel.y;

	this->setX(currentPos.x);
	this->setY(currentPos.y);
}

void Player::update()
{	
	if (this->getPos().y < 296)
	{
		velocity.y += gravity;
	}
	else
	{
		velocity.y = 0;
		this->setY(296);
	}
      
    this->move(Vector2f(velocity.x, velocity.y));
}