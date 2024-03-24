#include "player.h"
 
Player:: Player(SDL_Renderer* renderer) : playerX(0),playerY(260),playerWidth(0),playerHeight(0),playing(true),frame(0)
{
    const char* playerPath ="player1-run.png";
    playerTexture=IMG_LoadTexture(renderer,playerPath);
    SDL_Rect ret;
    SDL_QueryTexture(playerTexture,NULL,NULL,&ret.w,&ret.h);
    playerWidth=ret.w/6;
    playerHeight=ret.h;
}
void Player:: draw(SDL_Renderer* renderer){
    SDL_Rect playerRect[6];
    SDL_Rect des ={0,130,530,150};
    for(int i=0;i<6;i++){
        playerRect[i].x=i*playerWidth;
        playerRect[i].y=130;
        playerRect[i].w=playerWidth;
        playerRect[i].h=playerHeight;
    }
    SDL_RenderCopy(renderer,playerTexture,&playerRect[frame],&des);
}
void Player:: changeFrames(){
    frame%6 +1;
 
}
void Player:: resetPosition(){
    if(playerX>=600) playerX=0;
}

    
