#include "player.h"
 
Player:: Player(SDL_Renderer* renderer) : X(120),Y(495),Width(0),Height(0),playing(true),frame(0),elapse(0)
{
    const char* playerPath ="DinoSprites.png";
    playerTexture=IMG_LoadTexture(renderer,playerPath);
    SDL_Rect ret;
    state=Playerstate::RUN;
    SDL_QueryTexture(playerTexture,NULL,NULL,&ret.w,&ret.h);
    Width=ret.w/15;
    Height=ret.h;
    for(int i=0;i<15;i++){
        playerRect[i].x=i*Width;
        playerRect[i].y=0;
        playerRect[i].w=Width;
        playerRect[i].h=Height;
    }
}
void Player:: draw(SDL_Renderer* renderer){
   
    SDL_Rect des ={X,Y,80,80};
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
	SDL_RenderDrawRect(renderer,&des);
    SDL_RenderCopy(renderer,playerTexture,&playerRect[frame],&des);
}
void Player::update(){
    changeFrames();
    if(state==Playerstate::UP){
        Y-=2;
        if(Y<=320){
            floattime=0;
            state=Playerstate::FLOAT;
        }
    }
    if(state==Playerstate::FLOAT){
        floattime++;
        if(floattime>=24){
            state=Playerstate::DOWN;
            floattime=0;
        }
    }
    if(state==Playerstate::DOWN){
        Y+=2;
        if(Y>=495) state=Playerstate::RUN;
    }
}
void Player:: changeFrames(){
    elapse ++;
    if(elapse%100==0){
        frame=(frame+1)%15;
    } 
    
 
}

    
