#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
class Background {
public:
    Background(SDL_Renderer* renderer); 
    void draw(SDL_Renderer* renderer);
    void drawStartbutton(SDL_Renderer* renderer);

private:
    SDL_Texture* skyTexture;
    SDL_Texture* groundTexture;
};