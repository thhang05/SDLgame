#pragma once 
##include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Player {
    public :
      Player(SDL_Renderer* renderer);
      void draw (SDL_Renderer* renderer);
      void show (SDL_Renderer* renderer);
      




      private:
       SDL_Texture* player;
      
       float playerX,playerY,playerWidth,playerHeight;
       int frame;
       bool playing;
       

}
