#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Math.hpp"
#include "Entity.hpp"

class Ground : public Entity
{
public:
	Ground(Vector2f p_pos, int p_length, SDL_Texture* p_tex);
	std::vector<Entity> getTiles();

private:
	std::vector<Entity> groundTiles;
};