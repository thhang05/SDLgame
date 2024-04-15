#include "predator.h"
#include <cstdlib>
#include<ctime>
#include<random>
Predator :: Predator(SDL_Renderer* renderer):monsterTexture(nullptr) ,fireTexture(nullptr),MonsterX(0),MonsterY(100),FireX(0),FireY(500),frame(0),monsterSpeed(1),firespeed(2),
                                             monsterWidth(83),monsterHeight(83),fireWidth(50),fireHeight(50),speedchanger(0),elapse(0)
{
   //srand(time(NULL));
   //MonsterX = rand()%150+300;
   //FireX=rand()%120+850;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> mons_dis(300,450);
    std::uniform_int_distribution<> fire_dis(850,970);
    std::uniform_int_distribution<> mons_hei (200,350);
    MonsterX=mons_dis(gen);
    FireX=fire_dis(gen)  ; 
    MonsterY=mons_hei(gen);
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
    //SDL_SetRenderDrawColor(renderer,255,0,0,255);
	//SDL_RenderDrawRect(renderer,&desMon);
    SDL_RenderCopy(renderer,monsterTexture,&monsterRect[frame],&desMon);
    SDL_Rect desFire ={FireX,FireY,60,60};
    //SDL_RenderDrawRect(renderer,&desFire);
    SDL_RenderCopy(renderer,fireTexture,NULL,&desFire);
}
void Predator:: move(){
    MonsterX-=monsterSpeed;
    FireX-=firespeed;
    
}
void Predator:: resetPosition(){
    if(MonsterX<=1) {
         std::random_device rd;
         std::mt19937 gen(rd());
         std::uniform_int_distribution<> mons_dis(300,450);
         std::uniform_int_distribution<> mons_heig(200,350);
         MonsterX=mons_dis(gen);
         MonsterY=mons_heig(gen);
    }
    if(FireX<=1){
       std::random_device rd;
       std::mt19937 gen(rd());
       std::uniform_int_distribution<> fire_dis(850,970);
       FireX=fire_dis(gen);
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
    resetPosition();
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




