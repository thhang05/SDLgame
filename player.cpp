#include "player.h"
 
Player:: Player(SDL_Renderer* renderer) : playerX(120),playerY(480),playerWidth(0),playerHeight(0),playing(true),frame(0),elapse(0)
{
    const char* playerPath ="DinoSprites.png";
    playerTexture=IMG_LoadTexture(renderer,playerPath);
    SDL_Rect ret;
    SDL_QueryTexture(playerTexture,NULL,NULL,&ret.w,&ret.h);
    playerWidth=ret.w/15;
    playerHeight=ret.h;
}
void Player:: draw(SDL_Renderer* renderer){
    SDL_Rect playerRect[15];
    SDL_Rect des ={playerX,playerY,100,100};
    for(int i=0;i<15;i++){
        playerRect[i].x=i*playerWidth;
        playerRect[i].y=0;
        playerRect[i].w=playerWidth;
        playerRect[i].h=playerHeight;
    }
    SDL_RenderCopy(renderer,playerTexture,&playerRect[frame],&des);
}
void Player:: changeFrames(){
    elapse ++;
    if(elapse%100==0){
        frame=(frame+1)%15;
    } 
    
 
}

    
