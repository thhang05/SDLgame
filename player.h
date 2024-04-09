#pragma once 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Player {
    public :
      Player(SDL_Renderer* renderer);
      void draw (SDL_Renderer* renderer);
      void changeFrames ();
      
       SDL_Texture* playerTexture;
      
       int X,Y,Width,Height;
       int frame;
       bool playing;
       int elapse;
       

};
