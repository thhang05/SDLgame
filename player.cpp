#include "player.h"
 
Player:: Player(SDL_Renderer* renderer) : X(120),Y(480),Width(0),Height(0),playing(true),frame(0),elapse(0)
{
    const char* playerPath ="DinoSprites.png";
    playerTexture=IMG_LoadTexture(renderer,playerPath);
    SDL_Rect ret;
    SDL_QueryTexture(playerTexture,NULL,NULL,&ret.w,&ret.h);
    Width=ret.w/15;
    Height=ret.h;
}
void Player:: draw(SDL_Renderer* renderer){
    SDL_Rect playerRect[15];
    SDL_Rect des ={X,Y,100,100};
    for(int i=0;i<15;i++){
        playerRect[i].x=i*Width;
        playerRect[i].y=0;
        playerRect[i].w=Width;
        playerRect[i].h=Height;
    }
    SDL_RenderCopy(renderer,playerTexture,&playerRect[frame],&des);
}
void Player:: changeFrames(){
    elapse ++;
    if(elapse%100==0){
        frame=(frame+1)%15;
    } 
    
 
}

    
