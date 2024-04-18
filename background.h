#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
class Background {
public:
    int elapse;
    int frame;
    SDL_Rect SkyRect[60];
    Background(SDL_Renderer* renderer); 
    void update(SDL_Renderer* renderer);
    void draw(SDL_Renderer* renderer);
    void drawStartbutton(SDL_Renderer* renderer);
    void drawNewGameButton(SDL_Renderer* renderer);
private:
    SDL_Texture* skyTexture;
    SDL_Texture* groundTexture;
    SDL_Texture* newgameTexture;
};