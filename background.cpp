#include "background.h"

Background::Background(SDL_Renderer* renderer) : skyTexture(nullptr), groundTexture(nullptr) {
    const char* groundPath = "ground.bmp";
    groundTexture = IMG_LoadTexture(renderer, groundPath);

    const char* skyPath = "sky.bmp";
    skyTexture = IMG_LoadTexture(renderer, skyPath);
    if (!groundTexture || !skyTexture) {
        std::cerr << "Lỗi tải kết cấu: " << SDL_GetError() << std::endl;
    }
}

void Background::draw(SDL_Renderer* renderer) {
    SDL_Rect skyRect = {0, 0, 600, 260};
    SDL_Rect groundRect = {0, 260,600, 100};
    

    SDL_RenderCopy(renderer, skyTexture, NULL, &skyRect);
    SDL_RenderCopy(renderer, groundTexture, NULL, &groundRect);
}
void Background :: drawStartbutton (SDL_Renderer* renderer){
    const char* startpath="startbutton.png";
    SDL_Texture* startTexture= IMG_LoadTexture(render,startpath);
     if (!startTexture ) {
        std::cerr << "Lỗi tải kết cấu: " << SDL_GetError() << std::endl;
    }
    SDL_Rect startRect={200,220,200,50};
    SDL_RenderCopy(renderer,startTexture,NULL,&startRect);
}