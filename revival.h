#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<iostream>
#include "player.h"

class Revival {
    public :
     Revival(SDL_Renderer* renderer);
     void draw (SDL_Renderer* renderer);
     void move();
     bool collide (Player &player,Revival &revival);
     void update();
     void resetPosition();
     bool iscollided ;
   
    int velocity ;
    int Xmin ;
    SDL_Texture* bloodTexture ;
    int X,Y ;
    int W,H;



};