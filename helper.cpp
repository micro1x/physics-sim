#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

struct WindowResources
{
    SDL_Window* window;
    SDL_Renderer* renderer;
};

void getMousePos(float x, float y)
{
    SDL_GetMouseState(&x,&y);
    printf("Window Position -> X: %0f, Y: %0f\n", x, y);
}

WindowResources create_window()
{
    SDL_Window *window = SDL_CreateWindow(
        "Physics simulator",                  // window title
        1280,                               // width, in pixels
        720,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    if (window == NULL) {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return {nullptr,nullptr};
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    return {window, renderer};
}

void create_Menu(SDL_Renderer* renderer)
{
    SDL_FRect rect1;
    SDL_FRect visualizerWindow;            // Window where visuals will show

    rect1 = {0,0,1280,720};
    visualizerWindow = {13,12,830,480};
   
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 89,90,88, SDL_ALPHA_OPAQUE);
    SDL_RenderRect(renderer, &rect1);
    SDL_RenderFillRect(renderer, &rect1);
    SDL_SetRenderDrawColor(renderer, 0,0,0, SDL_ALPHA_OPAQUE);
    SDL_RenderRect(renderer, &visualizerWindow);
    SDL_RenderFillRect(renderer,&visualizerWindow);
}