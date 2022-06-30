#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Math.hpp"

class Player : public Entity
{
public:
	Player(Vector2f p_pos, SDL_Texture* p_tex);
	void move(Vector2f p_vel);
private:
	Vector2f velocity;
};