#include "revival.h"
#include<random>

Revival::Revival(SDL_Renderer* renderer) :bloodTexture(nullptr),velocity(1),X(0),Y(0),W(35),H(45),iscollided(false),Xmin(-150)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> blood_dis(700,900);
    std::uniform_int_distribution<> blood_hei(300,350);

    X=blood_dis(gen);
    Y=blood_hei (gen);

    const char* bloodPath ="blood.png";
    bloodTexture =IMG_LoadTexture(renderer,bloodPath);
    if(!bloodTexture){
        std::cerr<<"Khong tai duoc be mat  :"<<SDL_GetError()<<std::endl;
    }


}
void Revival::draw(SDL_Renderer* renderer){
    SDL_Rect des ={X,Y,W,H};
    //SDL_SetRenderDrawColor(renderer,255,0,0,255);
	//SDL_RenderDrawRect(renderer,&des);
    SDL_RenderCopy(renderer,bloodTexture,NULL,&des);
}
void Revival::move(){
    X-=velocity;
}
void Revival::resetPosition(){
  
   
    if(X<=Xmin||iscollided==true){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> blood_dis(1100,1300);
        std::uniform_int_distribution<> blood_hei(300,400);

        X=blood_dis(gen);
        Y=blood_hei (gen);
        Xmin-=5;
       
        
}
}
bool Revival:: collide(Player &player,Revival &revival)
{
    
    if (player.X <= revival.X +W &&
        player.X + 80 >= revival.X &&
        player.Y + 80 >= revival.Y &&
        player.Y <= revival.Y + 80
        )
        {
            iscollided=true;
        }
    return iscollided ; 

}
void Revival::update(){
    move();
    resetPosition();
}