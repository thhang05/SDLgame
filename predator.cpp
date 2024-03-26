#include "predator.h"
#include <ctsdlib>
#include<ctime>
Predator :: Predator(SDL_Renderer* renderer):monsterTexture(nullptr) ,fireTexture(nullptr),MonsterX(0),MonsterY(120),FireX(0),FireY(180),frame(0),monsterSpeed(3),firespeed(2),
                                             monsterWidth(83),monsterHeight(83),fireWidth(50),fireHeight(50),speedchanger(0)
{
    scrand(time(NULL));
    MonsterX = rand()%150+400;
    FireX=rand()%120+350;

   
    const char* monsterPath ="predator.png";
    const char* firePath ="fire.jpg";
    monsterTexture=IMG_LoadTexture(renderer,monsterPath);
    fireTexture = IMG_LoadTexture(renderer,firePath);
     if (!monsterTexture || !fireTexture) {
        std::cerr << "Lỗi tải kết cấu: " << SDL_GetError() << std::endl;
    }
}
void Predator:: draw(SDL_Renderer* renderer){
    SDL_Rect monsterRect[6] ;
    SDL_Rect desMon ={MonsterX,MonsterY,50,50};
    for(int i=0;i<6;i++){
        monsterRect[i].x=i*monsterWidth;
        monsterRect[i].y=0;
        monsterRect[i].w=83;
        monsterRect[i].h=83;
    }
    SDL_RenderCopy(renderer,monsterTexture,&monsterRect,&desMon);
    SDL_Rect desFire ={FireX,FireY,50,50};
    SDL_RenderCopy(renderer,fireTexture,NULL,&desFire;)
}
void Predator:: move(){
    MonsterX-=monsterSpeed;
    FireX-=firespeed;
    speedchanger++;
    if(speedchanger%100==0&&monsterSpeed<30&&firespeed<30){
        
    }

}
