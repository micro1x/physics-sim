#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>


int main(int argc, char* argv[]) {

    SDL_FRect rect1;
    SDL_Window *window;                    // Declare a pointer
    bool done {false};
    SDL_Renderer* renderer;

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL3
    rect1.x = 0;
    rect1.y = 0;
    rect1.w = 50;
    rect1.h = 50;
    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Physics simulator",                  // window title
        1280,                               // width, in pixels
        720,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    
    renderer = SDL_CreateRenderer(window, nullptr);

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderRect(renderer, &rect1);
    SDL_RenderFillRect(renderer, &rect1);
    SDL_RenderPresent(renderer);

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
            
        }
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}