#pragma once 
#include<iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "player.h"
class Predator {
    public :
     Predator(SDL_Renderer* renderer);
     void draw(SDL_Renderer* renderer);
     void move();
     void changeFrame();
     void resetPosition(Player &player);
     void update(Player &player);
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
     int framemons;
     int framefire ;
     float monsterSpeed;
     float firespeed;
     int monsterWidth;
     int monsterHeight;
     int fireWidth ;
     int fireHeight ;
     long long  speedchanger ;
     int elapse ;




};
