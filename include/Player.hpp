#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Entity.hpp"
#include "Math.hpp"

class Player : public Entity
{
public:
	float gravity = 0.09f;
	Player(Vector2f p_pos, Vector2f p_vel, SDL_Texture* p_tex);
	void setVelocity(Vector2f p_vel);
	Vector2f getVelocity();
	void move(Vector2f p_vel);
	void update();

private:
	Vector2f velocity;
};