#pragma once 
#include<iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Predator {
    public :
     Predator(SDL_Renderer* renderer);
     void draw(SDL_Renderer* renderer);
     void move();
     void changeFrame();
     void resetPostion();
     void update();
     int getMonsterX();
     int getMonsterY();
     int getFireX();
     int getFireY();
     SDL_Texture* monsterTexture ;
     SDL_Texture* fireTexture ;
     int MonsterX;
     int MonsterY;
     int FireX;
     int FireY;
     int frame;
     int monsterSpeed;
     int firespeed;
     int monsterWidth;
     int monsterHeight;
     int fireWidth ;
     int fireHeight ;
     long long  speedchanger ;
     int elapse ;




};
