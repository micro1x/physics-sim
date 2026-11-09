#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>


int main()
{
    SDL_Log("Available renderer drivers:");
    for (int i = 0; i < SDL_GetNumRenderDrivers(); i++) {
        SDL_Log("%d. %s", i + 1, SDL_GetRenderDriver(i));
    }
    return 0;
}