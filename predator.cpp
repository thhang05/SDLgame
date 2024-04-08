#include "predator.h"
#include <cstdlib>
#include<ctime>
Predator :: Predator(SDL_Renderer* renderer):monsterTexture(nullptr) ,fireTexture(nullptr),MonsterX(0),MonsterY(300),FireX(0),FireY(450),frame(0),monsterSpeed(0.5),firespeed(0.5),
                                             monsterWidth(83),monsterHeight(83),fireWidth(50),fireHeight(50),speedchanger(0),elapse(0)
{
   srand(time(NULL));
   MonsterX = rand()%150+400;
   FireX=rand()%120+350;
    
   
    const char* monsterPath ="predator.png";
    const char* firePath ="fire.png";
    monsterTexture=IMG_LoadTexture(renderer,monsterPath);
    fireTexture = IMG_LoadTexture(renderer,firePath);
     if (!monsterTexture || !fireTexture) {
        std::cerr << "Lỗi tải kết cấu: " << SDL_GetError() << std::endl;
    }
}
void Predator:: draw(SDL_Renderer* renderer){
    SDL_Rect monsterRect[6] ;
    SDL_Rect desMon ={MonsterX,MonsterY,80,80};
    for(int i=0;i<6;i++){
        monsterRect[i].x=i*monsterWidth;
        monsterRect[i].y=0;
        monsterRect[i].w=83;
        monsterRect[i].h=83;
    }
    SDL_RenderCopy(renderer,monsterTexture,&monsterRect[frame],&desMon);
    SDL_Rect desFire ={FireX,FireY,150,150};
    SDL_RenderCopy(renderer,fireTexture,NULL,&desFire);
}
void Predator:: move(){
    MonsterX-=monsterSpeed;
    FireX-=firespeed;
    
}
void Predator:: resetPostion(){
    if(MonsterX<=-40) {
         srand(time(NULL));
         MonsterX = rand()%280+1000;
    }
    if(FireX<=-40){
        srand(time(NULL));
        FireX=rand()%280+1000;
    }
}
void Predator:: changeFrame(){
    elapse++;
    if(elapse==100){
        frame=(frame+1);
        if(frame>5)
            frame=0;
    }
    else if(elapse>100)
        elapse=0;

}
void Predator:: update(){
    changeFrame();
    move();
    resetPostion();
}
int Predator:: getMonsterX(){
    return MonsterX;
}
int Predator::getMonsterY(){
    return MonsterY;
}
int Predator::getFireX(){
    return FireX;
}
int Predator::getFireY(){
    return FireY;
}




