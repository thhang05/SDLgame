all:
	g++ -I D:\Sourcefile\include -L d:\Sourcefile\lib -o main main.cpp background.cpp player.cpp predator.cpp revival.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer 
	