#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include<windows.h>
#include <iostream>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_ttf.h>
#include<string>


#include "background.h"
#include "player.h"
#include "predator.h"

using namespace std;

const int PLAYERWIDTH =80 ;
const int PLAYERHEIGHT =80;
const int MONSTERWIDTH =80;
const int MONSTERHEIGHT =80;
const int FIREWIDTH = 90;
const int FIREHEIGHT =90;
string scorePath="Your Score";
string diem ;


int mTicksCount = 0;
int count=3;
int score ;
int elapse=0;

bool quit=false;
bool restart = false;

SDL_Event e;
SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;
const Uint8* keys;
SDL_Texture* newgameTexture ;
Mix_Chunk* jumpsound =NULL;
Mix_Music* runsound =NULL;
TTF_Font* gfont =NULL;
SDL_Surface* textSurface=NULL ;


void output(SDL_Renderer* renderer,Background &background,Player &player,Predator &predator);
void GameStart (SDL_Renderer* renderer,Background &background,Player &player,Predator &predator);
bool checkCollision(Player &player,Predator &predator);
void resetGame (Player &player,Predator &predator,Background &background);
void update();
void loadSound();
void loadText( string path,int frame);


int main(int argc, char* argv[]) 
{
    
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    { 
        cerr << "Lỗi khởi tạo SDL: " << SDL_GetError() << endl;
        return 1; 
    }

    if (!(IMG_Init(IMG_INIT_PNG))) 
    {
        cerr << "Lỗi khởi tạo SDL_Image: " << SDL_GetError() << endl;
         return 1;
    }

    window = SDL_CreateWindow( "The adventure of elemental", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280,720,SDL_WINDOW_SHOWN);

     if (!window) 
     {
        cerr << "Lỗi tạo cửa sổ: " << SDL_GetError() << endl;
        return 1; 
     }

    renderer = SDL_CreateRenderer( window,-1, SDL_RENDERER_ACCELERATED);

    if (!renderer) 
    {
        cerr << "Lỗi tạo trình kết xuất: " << SDL_GetError() << endl;
        return 1; 
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cerr<< "SDL_mixer không thể khởi tạo! Lỗi SDL_mixer :"<<Mix_GetError()<<endl ;
        return 1;
    }
    if( TTF_Init() == -1 ) 
                { 
                    cerr<<"SDL_ttf không thể khởi tạo! Lỗi SDL_ttf: "<< TTF_GetError() ; 
                    return 1;
                }
    loadSound();
    //loadText();
    
    
    
    Background background(renderer);  
    background.draw(renderer);
    background.drawStartbutton(renderer);
    SDL_RenderPresent(renderer);
    Player player(renderer);
    Predator predator(renderer);
    int x,y;
    while(!quit)
    {
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

                               if(x>540&&x<740&&y>335&&y<380)
                               {
                                  Mix_PlayMusic(runsound,-1);
                                  //loadText();
                                  background.heart=3 ;
                                  score=0;
                                  GameStart(renderer,background,player,predator) ;
                                  update() ;
                               }
                           
                           
                            break ;
                        
                    }
                }
    }   
    Mix_FreeChunk(jumpsound);
    SDL_FreeSurface(textSurface);
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window);
    IMG_Quit();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
    
    return 0; 
}
void output(SDL_Renderer* renderer,Background &background,Player &player,Predator &predator){
    SDL_RenderClear(renderer);
    background.draw(renderer);
    player.draw(renderer);
    predator.draw(renderer);
    background.drawBlood(renderer);
    loadText(scorePath,0);
    loadText(diem,1);
    if(background.heart==0)
        
        {
            background.drawNewGameButton(renderer);
            Mix_PauseMusic();
        }    
        
    SDL_RenderPresent(renderer);
}
void GameStart (SDL_Renderer* renderer,Background &background,Player &player,Predator &predator){
    
    resetGame(player,predator,background);
    while(!quit&&background.heart!=0)
    {
        Sleep(1);
        elapse++;
        if(elapse==20){
            score++;
            elapse=0;
        }
        diem=to_string(score);
        background.update(renderer);
        keys = SDL_GetKeyboardState(NULL);
	    if (keys[SDL_SCANCODE_SPACE]&&player.state==Playerstate::RUN)
        {
            Mix_PlayChannel( -1, jumpsound, 0);
		    player.state=Playerstate::UP;
    
            
            
        }
        
        if(!checkCollision(player,predator))
        {
          background.heart--;
          SDL_Delay(200);
          resetGame(player,predator,background);
          
         }
        output(renderer,background,player,predator);
        
        player.update();
        predator.update(player);
        
        
        
       while( SDL_PollEvent( &e ) != 0 )
                {
                    switch(e.type){
                        case SDL_QUIT :
                           quit=true;
                           break;
                    }
                }
    }
}

bool checkCollision (Player &player,Predator &predator){
     if (
        player.X <= predator.MonsterX + MONSTERWIDTH/2+10 &&
        player.X + PLAYERWIDTH/2 >= predator.MonsterX &&
        player.Y + PLAYERHEIGHT/2 >= predator.MonsterY &&
        player.Y <= predator.MonsterY + MONSTERHEIGHT/2
    )
    {
        player.playing = false;
    }

    if (
        player.X <= predator.FireX +FIREWIDTH/2 &&
        player.X + PLAYERWIDTH/2 >= predator.FireX &&
        player.Y + PLAYERHEIGHT/2 >= predator.FireY &&
        player.Y <= predator.FireY + FIREHEIGHT/2
    )
    {
        player.playing = false;    
    }
    return player.playing ;
   
}
void resetGame (Player &player,Predator &predator,Background &background){
    player.Y=495 ;
    player.state=Playerstate::RUN;
    predator.resetPosition(player);
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
void loadSound(){
    jumpsound = Mix_LoadWAV("jump.wav");
           
      if(jumpsound==NULL)
            {
                cerr<<"Khong tai duoc hieu ung am thanh : "<<Mix_GetError()<<endl;

            }
    runsound=Mix_LoadMUS("newrun.mp3");
    
    if(runsound==NULL)
    {
           cerr<<"Khong tai duoc am nhac : "<<Mix_GetError()<<endl;
    }
}
void loadText ( string path,SDL_Rect des)
{
     gfont=TTF_OpenFont("font.ttf",36);
     if(gfont==NULL){
        cerr<<"Khong the mo font : "<<TTF_GetError()<<endl;
     }
     SDL_Color textColor={255,255,255};
     textSurface = TTF_RenderText_Solid(gfont, path.c_str(), textColor);
     SDL_Texture* textTexture;
     if(textSurface==NULL){
        cerr<<"Khong the hien thi be mat van ban : "<<TTF_GetError();
     }
     else 
     {
       textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
      if(textTexture==NULL){
        cerr<<"Khong the tao hoa tiet tu van ban duoc hien thi : "<<SDL_GetError();

      }
     }
     SDL_Rect textRect[2];
     
     textRect[1].x = 50
     textRect[1].y = 50;
     textRect[1].w = textSurface->w;
     textRect[1].h = textSurface->h;
     
     SDL_RenderCopy(renderer, textTexture, NULL, &textRect[frame]);
    
     TTF_CloseFont(gfont);
}
