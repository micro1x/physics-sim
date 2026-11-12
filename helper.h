#pragma once

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

struct WindowResources
{
    SDL_Window* window;
    SDL_Renderer* renderer;
};

WindowResources create_window();
void create_Menu(SDL_Renderer* renderer);
void getMousePos(float x, float y);
void createText();