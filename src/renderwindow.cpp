#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) 
:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (window == NULL) 
	{
		std::cout << "window failed to init, Error: " << SDL_GetError() << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) 
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
	{
		std::cout << "Failed to load texture. Error " << SDL_GetError() << std::endl;
	}

	return texture;
}


void RenderWindow::cleanUp() 
{
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 135, 206, 235, 255);
}

void RenderWindow::render(Entity& p_entity) 
{
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPos().x * 2;
	dst.y = p_entity.getPos().y * 2;
	dst.w = p_entity.getCurrentFrame().w * 2;
	dst.h = p_entity.getCurrentFrame().h * 2;
	
	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}