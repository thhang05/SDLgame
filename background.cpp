#include "background.h"

Background::Background(SDL_Renderer* renderer) : skyTexture(nullptr), groundTexture(nullptr),heart(3){
    const char* groundPath = "ground.bmp";
    groundTexture = IMG_LoadTexture(renderer, groundPath);

    const char* skyPath = "sky2.png";
    skyTexture = IMG_LoadTexture(renderer, skyPath);
    if (!groundTexture || !skyTexture) {
        std::cerr << "Lỗi tải kết cấu: " << SDL_GetError() << std::endl;
    }
    else{
        frame=0;
        elapse=0;
        for(int i = 0 ; i < 60; i++)
            SkyRect[i] = {10*i,0,600,260};
    }
    const char* bloodPath ="myheart.png";
    bloodTexture = IMG_LoadTexture(renderer,bloodPath);
    if(!bloodTexture){
        std::cerr<<"Lỗi tải kết cấu: " << SDL_GetError() << std::endl;
    }
}
void Background::update(SDL_Renderer* renderer){
    elapse++;
    if(elapse>=20){
        frame++;
        elapse=0;
    }
    if(frame>=60)   frame = 0;
    draw(renderer);

}
void Background::draw(SDL_Renderer* renderer) {
    SDL_Rect skyRect = {0, 0, 1280, 620};
    SDL_Rect groundRect = {0, 560,1280, 300};
    SDL_RenderCopy(renderer, skyTexture, &SkyRect[frame], &skyRect);
    SDL_RenderCopy(renderer, groundTexture, NULL, &groundRect);
}
void Background :: drawStartbutton (SDL_Renderer* renderer){
    const char* startpath="startbutton.png";
    SDL_Texture* startTexture= IMG_LoadTexture(renderer,startpath);
     if (!startTexture ) {
        std::cerr << "Lỗi tải kết cấu: " << SDL_GetError() << std::endl;
    }
    SDL_Rect startRect={540,335,200,50};
    SDL_RenderCopy(renderer,startTexture,NULL,&startRect);
}
void Background:: drawexitbutton(SDL_Renderer* renderer){
    const char* exitPath= "exitbutton.png";
    SDL_Texture* exitTexture=IMG_LoadTexture(renderer,exitPath);
    if (!exitTexture ) {
        std::cerr << "Lỗi tải kết cấu: " << SDL_GetError() << std::endl;
    }
    SDL_Rect des={540,400,200,50};
    SDL_RenderCopy(renderer,exitTexture,NULL,&des);
}
void Background:: drawNewGameButton(SDL_Renderer* renderer){
     const char* newPath ="newgame.png";
     SDL_Texture* newgameTexture ;
     newgameTexture = IMG_LoadTexture(renderer,newPath);
    if(!newgameTexture){
        std:: cerr << "Lỗi tải kết cấu: " << SDL_GetError() <<std::endl;
    }
    SDL_Rect desnew ={540,335,200,50};
    SDL_RenderCopy(renderer,newgameTexture,NULL,&desnew);
    SDL_RenderPresent(renderer);
}
void Background:: drawBlood (SDL_Renderer* renderer){
    SDL_Rect blooddes[3];
    blooddes[0].x=1080;
    blooddes[0].y=20;
    blooddes[0].w=60;
    blooddes[0].h=60;

    blooddes[1].x=1140;
    blooddes[1].y=20;
    blooddes[1].w=60;
    blooddes[1].h=60;

    blooddes[2].x=1200;
    blooddes[2].y=20;
    blooddes[2].w=60;
    blooddes[2].h=60;

    for(int i=0;i<heart;i++){
        SDL_RenderCopy(renderer,bloodTexture,NULL,&blooddes[i]);
    }
}
void Background::drawFirstBg(SDL_Renderer* renderer){
    const char* bgPath= "the.png";
    firstTexture = IMG_LoadTexture(renderer,bgPath);
    if(!firstTexture){
        std::cerr<<"loi tai ket cau : "<<SDL_GetError()<<std::endl;
    }
    SDL_Rect des={0,0,1280,720};
    SDL_RenderCopy(renderer,firstTexture,NULL,&des);
}