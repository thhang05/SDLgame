#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<windows.h>
#include <iostream>

#include "background.h"
#include "player.h"
#include "predator.h"
using namespace std;
const int PLAYERWIDTH =100 ;
const int PLAYERHEIGHT =100;
const int MONSTERWIDTH =80;
const int MONSTERHEIGHT =80;
const int FIREWIDTH = 60;
const int FIREHEIGHT =60;
int mTicksCount = 0;
bool quit=false;
SDL_Event e;
SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;
const Uint8* keys;
void output(SDL_Renderer* renderer,Background &background,Player &player,Predator &predator);
void GameStart (SDL_Renderer* renderer,Background &background,Player &player,Predator &predator);
bool checkCollision(Player &player,Predator &predator);
void resetGame (Player &player,Predator &predator);
void update();



int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) { 
        cerr << "Lỗi khởi tạo SDL: " << SDL_GetError() << endl;
        return 1; 
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        cerr << "Lỗi khởi tạo SDL_Image: " << SDL_GetError() << endl;
         return 1;
    }
    window = SDL_CreateWindow( "The adventure of elemental", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280,720,SDL_WINDOW_SHOWN);

     if (!window) {
        cerr << "Lỗi tạo cửa sổ: " << SDL_GetError() << endl;
        return 1; 
     }

    renderer = SDL_CreateRenderer( window,-1, SDL_RENDERER_ACCELERATED);

    if (!renderer) {
        cerr << "Lỗi tạo trình kết xuất: " << SDL_GetError() << endl;
        return 1; 
    }

    Background background(renderer);  
    background.draw(renderer);
    background.drawStartbutton(renderer);
    SDL_RenderPresent(renderer);
    Player player(renderer);
    Predator predator(renderer);
    int x,y;
    while(!quit){
        Uint32 windowID = SDL_GetWindowID(window);
         while( SDL_PollEvent( &e ) != 0 )
                {
                    switch(e.type){
                        case SDL_QUIT :
                           quit=true;
                           break;
                        case SDL_MOUSEBUTTONDOWN :
                           x=e.button.x;
                           y=e.button.y;
                           /*if(x>540&&x<740&&y>335&&y<380){
                               GameStart(renderer,background,player,predator);
                           } 
                           if(!checkCollision(player,predator)){
                                 background.drawNewGameButton(renderer);
                                 if(x>540&&x<720&&y>350&&y<450){
                                    resetGame(player,predator);
                                    GameStart(renderer,background,player,predator);
                                 }
                            }
                            break;
                             */ 
                           
                               if(x>540&&x<740&&y>335&&y<380){
                               GameStart(renderer,background,player,predator);
                               update();
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
void output(SDL_Renderer* renderer,Background &background,Player &player,Predator &predator){
    SDL_RenderClear(renderer);
    background.draw(renderer);
    player.draw(renderer);
    predator.draw(renderer);
    SDL_RenderPresent(renderer);
}
void GameStart (SDL_Renderer* renderer,Background &background,Player &player,Predator &predator){
    while(checkCollision(player,predator)&&!quit){
        Sleep(2);
        player.Y=480;
        keys = SDL_GetKeyboardState(NULL);
	    if (keys[SDL_SCANCODE_SPACE]){
		    player.Y-=100;
        }
        output(renderer,background,player,predator);
        player.changeFrames();
        
        //std::cout<<predator.MonsterX<<" ";
        predator.update();
         while( SDL_PollEvent( &e ) != 0 )
                {
                    switch(e.type){
                        case SDL_QUIT :
                           quit=true;
                           break;
                    }
                }
        
       
   
    }
   if(!checkCollision(player,predator)){
        const char* newPath ="newgame.png";
        SDL_Texture* newgameTexture ;
        newgameTexture = IMG_LoadTexture(renderer,newPath);
        if(!newgameTexture){
            cerr << "Lỗi tải kết cấu: " << SDL_GetError() <<endl;
        }
        SDL_Rect desnew ={540,350,180,100};
        SDL_RenderCopy(renderer,newgameTexture,NULL,&desnew);
        SDL_RenderPresent(renderer);
        int x,y;
        while(!quit){
        while( SDL_PollEvent( &e ) != 0 )
                {
                    switch(e.type){
                        case SDL_QUIT :
                           quit=true;
                           break;
                        case SDL_MOUSEBUTTONDOWN:
                           x=e.button.x;
                           y=e.button.y;
                            if(x>540&&x<720&&y>350&&y<450){
                                resetGame(player,predator);
                                checkCollision(player,predator);
                                GameStart(renderer,background,player,predator);
                            }
                            break;
                    }
                }
        }
    
    }
    
    
    
    
}
bool checkCollision (Player &player,Predator &predator){
     if (
        player.X <= predator.MonsterX + MONSTERWIDTH &&
        player.X + PLAYERWIDTH/2 >= predator.MonsterX &&
        player.Y + PLAYERHEIGHT >= predator.MonsterY &&
        player.Y <= predator.MonsterY + MONSTERHEIGHT/2+10
    ){
        player.playing = false;
    }

    if (
        player.X <= predator.FireX +FIREWIDTH &&
        player.X + PLAYERWIDTH/2+10 >= predator.FireX &&
        player.Y + PLAYERHEIGHT >= predator.FireY &&
        player.Y <= predator.FireY + FIREHEIGHT
    ){
        player.playing = false;    
    }
    return player.playing ;
   
}
void resetGame (Player &player,Predator &predator){
    player.Y=480 ;
    predator.resetPosition();
    player.playing=true ;
  
}
void update(){
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16)){}

    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

    if (deltaTime > 0.05f){
        deltaTime = 0.05f;
    }

    mTicksCount = SDL_GetTicks();
}


