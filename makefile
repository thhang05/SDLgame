all:
	g++ -I D:\Sourcefile\include -L d:\Sourcefile\lib -o main testbackground.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	