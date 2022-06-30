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
    //SDL_Texture* debugBlock = window.loadTexture(DEBUG_BLOCK_PATH);
    // Ground sprite spawner   

    Ground level0(Vector2f(0, (HEIGHT - 64)/2), 20, grassBlock);
    Ground level1(Vector2f(64, ((HEIGHT - 64)/2) - 32) , 5, grassBlock);

    Player player(Vector2f(0, 0), playerTexture);
      

    // Game Loop
    bool run = true;
    SDL_Event event;
    int vel = 1;

    while(run) 
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                run = false;
        }

        window.clear();
        for(Entity& g : level0.getTiles())
        {
            window.render(g);
        }
        for(Entity& g : level1.getTiles())
        {
            window.render(g);
        }

        if (player.getPos().x == (WIDTH/2)-32 && vel == 1)
        {
            vel *= -1;
        }else if (player.getPos().x == 0 && vel == -1)
        {
            vel *= -1;
        }
        
        player.move(Vector2f(vel, 0));

        window.render(player);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}