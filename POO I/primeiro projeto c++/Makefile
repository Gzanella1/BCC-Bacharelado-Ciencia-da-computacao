.PHONY: all clean doc

CXX=c++
CXXFLAGS=-g $(shell pkg-config sdl2  SDL2_ttf --cflags) 
SDL_LIBS=$(shell pkg-config sdl2  SDL2_ttf --libs) 
EXECUTABLES=main

#clematrix_test vector3_test window_test particle_test acceleration_test

all: $(EXECUTABLES)


main: main.cpp sdl.o 
	$(CXX) $(CXXFLAGS) main.cpp sdl.o  TextoSDL.h TextoSDL.cpp -o main $(SDL_LIBS)


doc:
	doxygen

clean:
	$(RM) *.o
	$(RM) $(EXECUTABLES)