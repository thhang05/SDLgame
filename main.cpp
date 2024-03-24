#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

#include "background.h"
#include "player.h"
using namespace std;
void output(SDL_Renderer* renderer,Background &background,Player &player){
    SDL_RenderClear(renderer);
    background.draw(renderer);
    player.draw(renderer);
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { 
        cerr << "Lỗi khởi tạo SDL: " << SDL_GetError() << endl;
        return 1; 
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        cerr << "Lỗi khởi tạo SDL_Image: " << SDL_GetError() << endl;
         return 1;
    }
     SDL_Window* window = SDL_CreateWindow( "The adventure of elemental", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600,360,SDL_WINDOW_SHOWN);

     if (!window) {
        cerr << "Lỗi tạo cửa sổ: " << SDL_GetError() << endl;
        return 1; 
     }

    SDL_Renderer* renderer = SDL_CreateRenderer( window,-1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        cerr << "Lỗi tạo trình kết xuất: " << SDL_GetError() << endl;
        return 1; 
    }

    Background background(renderer);
    background.draw(renderer);
    background.drawStartbutton(renderer);
    SDL_RenderPresent(renderer);
    bool quit=false;
    SDL_Event e;
     Player player(renderer);
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
                               output(renderer,background,player);
                           }

                           break;
                    }
                }
                }
   
   // player.changeFrames();
    
    //player.resetPosition();
   /* int count=0;
    SDL_Event event;
    while(!quit||count<18){
         while( SDL_PollEvent( &e ) != 0 )
                {
                    player.changeFrames();
                    output(renderer,background,player);
                    player.resetPosition();
                    count++;
                }
    }
    */


    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    
    return 0; 
}

