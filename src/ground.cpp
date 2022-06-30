#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>

#include "Ground.hpp"
#include "Math.hpp"
#include "RenderWindow.hpp"

Ground::Ground(Vector2f p_pos, int p_length, SDL_Texture* p_tex)
	:Entity(p_pos, p_tex)
{
	for(int i = 0;i < p_length; i ++)
    {
        {
        	Entity tile(Vector2f(p_pos.x + (32 * i), p_pos.y), p_tex);
        	groundTiles.push_back(tile);
        }
    }
}

std::vector<Entity> Ground::getTiles()
{
	return groundTiles;
}