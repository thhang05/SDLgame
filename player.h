#pragma once 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
enum struct Playerstate{
    RUN,UP,FLOAT,DOWN
};
class Player {
    public :
      Player(SDL_Renderer* renderer);
      void draw (SDL_Renderer* renderer);
      void update();
      void changeFrames ();
      Playerstate state;
      SDL_Texture* playerTexture;
      void resetPos();
       int X,Y,Width,Height;
       int frame;
       bool playing;
       int elapse;
       int floattime;
       SDL_Rect playerRect[15];

};

