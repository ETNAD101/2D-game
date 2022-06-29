#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Player.hpp"
#include "Math.hpp"

Player::Player(Vector2f p_pos, SDL_Texture* p_tex)
	:Entity{p_pos, p_tex}
{

}