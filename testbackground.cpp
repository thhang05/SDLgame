
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


class Background {
public:
    Background(SDL_Renderer* renderer); 
    void draw(SDL_Renderer* renderer);
    void drawStartbutton(SDL_Renderer* renderer);

private:
    SDL_Texture* skyTexture;
    SDL_Texture* groundTexture;
};

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
    SDL_Texture* startTexture= IMG_LoadTexture(renderer,startpath);
     if (!startTexture ) {
        std::cerr << "Lỗi tải kết cấu: " << SDL_GetError() << std::endl;
    }
    SDL_Rect startRect={200,220,200,50};
    SDL_RenderCopy(renderer,startTexture,NULL,&startRect);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { 
        std::cerr << "Lỗi khởi tạo SDL: " << SDL_GetError() << std::endl;
        return 1; 
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cerr << "Lỗi khởi tạo SDL_Image: " << SDL_GetError() << std::endl;
        return 1; // Báo lỗi
    }

    SDL_Window* window = SDL_CreateWindow( "The adventure of elemental", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600,360,SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "Lỗi tạo cửa sổ: " << SDL_GetError() << std::endl;
        return 1; // Báo lỗi
    }

    SDL_Renderer* renderer = SDL_CreateRenderer( window,-1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        std::cerr << "Lỗi tạo trình kết xuất: " << SDL_GetError() << std::endl;
        return 1; // Báo lỗi
    }

    Background background(renderer);
    background.draw(renderer);
    background.drawStartbutton(renderer);
    SDL_RenderPresent(renderer);
    bool quit=false;
    SDL_Event e;
    int x,y;
    while(!quit){
         while( SDL_PollEvent( &e ) != 0 )
                {
                    switch(e.type){
                        case SDL_QUIT :
                           quit=true;
                           break;
                        case SDL_MOUSEBUTTONDOWN :
                           x=e.button.x;
                           y=e.button.y;
                           if(x>200&&x<400&&y>220&&y<270){
                               background.draw(renderer);
                               SDL_RenderPresent(renderer);
                           }
                           break;
                    }
                }
                }
    
   

    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0; 
}





