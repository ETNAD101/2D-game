#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Settings.hpp" 
#include "Math.hpp"
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Ground.hpp"

int main(int argx, char *args[])
{
    // Window Initialization
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed, ERROR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_init has failed, ERROR: " << SDL_GetError() << std::endl;

    RenderWindow window(WINDOW_TITLE, WIDTH, HEIGHT);

    
    SDL_Texture* grassBlock = window.loadTexture(GROUND_TEXTURE_PATH);
    SDL_Texture* playerTexture = window.loadTexture(PLAYER_TEXTURE_PATH);
    // SDL_Texture* debugBlock = window.loadTexture(DEBUG_BLOCK_PATH);
    // Ground sprite spawner   
    std::vector<Ground> level ={Ground(Vector2f(0, 328), 20, grassBlock), 
                                Ground(Vector2f(64, 296), 5, grassBlock),
                                Ground(Vector2f(288, 296), 3, grassBlock),
                                Ground(Vector2f(96, 264), 3, grassBlock)
                                };

    Player player(Vector2f(0, 0), Vector2f(0,0), playerTexture);
      
    // Game Loop
    bool run = true;
    SDL_Event event;

    while(run) 
    {
        while(SDL_PollEvent(&event))
        {   
            switch(event.type)
            {
            case SDL_QUIT:
                run = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                player.setVelocity(Vector2f(0, 0));
                player.setX(0);
                player.setY(0);
                break;

            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_a)
                {
                    player.setVelocity(Vector2f(-3, player.getVelocity().y));
                }
                if(event.key.keysym.sym == SDLK_d)
                {
                    player.setVelocity(Vector2f(3, player.getVelocity().y));
                }
                if(event.key.keysym.sym == SDLK_SPACE)
                {
                    player.setVelocity(Vector2f(player.getVelocity().x, 10));
                }
                break;

            case SDL_KEYUP:
                player.setVelocity(Vector2f(0, player.getVelocity().y));
            }
        }

        window.clear();
        for(Ground& l : level)
        {
            for(Entity& g : l.getTiles())
            {
                window.render(g);
            }
        }
        
        player.update();
        window.render(player);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}