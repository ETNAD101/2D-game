#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Settings.hpp" 
#include "Math.hpp"
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Player.hpp"




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
    // Ground sprite spawner   
    std::vector<Entity> levelEntities;

    for(int x = 0;x < WIDTH/2; x += 32)
    {
        {
        Entity block(Vector2f(x, (HEIGHT - 64)/2), grassBlock);
        levelEntities.push_back(block);
        }
    }

    Player player(Vector2f(0, 0), playerTexture);
      

    // Game Loop
    bool run = true;
    SDL_Event event;

    while(run) 
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                run = false;
        }

        window.clear();
        for(Entity& e : levelEntities)
        {
            window.render(e);
        }
        window.render(player);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}