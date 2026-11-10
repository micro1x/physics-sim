#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include "helper.h"

float x;
float y;
bool done {false}; 
 

int main(int argc, char* argv[]) {
    
    WindowResources resources = create_window();
    SDL_Init(SDL_INIT_VIDEO);         
    create_Menu(resources.renderer);

    SDL_RenderPresent(resources.renderer);
    

    // Check that the window was successfully created


    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
            getMousePos(0,0);
        }
    }

    // Close and destroy the window
    SDL_DestroyWindow(resources.window);

    // Clean up
    SDL_Quit();
    return 0;
}