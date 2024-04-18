#include "background.h"

Background::Background(SDL_Renderer* renderer) : skyTexture(nullptr), groundTexture(nullptr) {
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