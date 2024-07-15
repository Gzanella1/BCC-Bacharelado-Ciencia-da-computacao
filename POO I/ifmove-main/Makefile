.PHONY: all clean doc

CXX=c++
CXXFLAGS=-g $(shell pkg-config sdl2  SDL2_ttf --cflags) 
SDL_LIBS=$(shell pkg-config sdl2  SDL2_ttf --libs) 
EXECUTABLES=acceleration_test

#clematrix_test vector3_test window_test particle_test acceleration_test

all: $(EXECUTABLES)

main: main.cpp
	$(CXX) main.cpp main

matrix_test: matrix.h array2.h matrix_test.cpp
	$(CXX) matrix_test.cpp -o matrix_test

vector3_test: matrix.h array2.h vector3.h vector3_test.cpp
	$(CXX) vector3_test.cpp -o vector3_test

window_test: window_test.cpp sdl.o window.o gcircle.o graphics.o mesh2.o gmesh2.o grid.o particle.o gparticle.o arrow2.o mesh2_utils.o gsquare.o gtriangle.o
	$(CXX) $(CXXFLAGS) window_test.cpp sdl.o window.o gcircle.o graphics.o mesh2.o gmesh2.o grid.o particle.o gparticle.o arrow2.o mesh2_utils.o gsquare.o gtriangle.o -o window_test $(SDL_LIBS)

acceleration_test: acceleration_test.cpp sdl.o window.o gcircle.o graphics.o mesh2.o gmesh2.o grid.o particle.o gparticle.o arrow2.o mesh2_utils.o gsquare.o gtriangle.o textoSDL.o
	$(CXX) $(CXXFLAGS) acceleration_test.cpp sdl.o window.o gcircle.o graphics.o mesh2.o gmesh2.o grid.o particle.o gparticle.o arrow2.o mesh2_utils.o textoSDL.o gsquare.o gtriangle.o -o acceleration_test $(SDL_LIBS)

particle_test: particle_test.cpp particle.o 
	$(CXX) particle_test.cpp particle.o -o particle_test

textoSDL.o: textoSDL.cpp textoSDL.h
	$(CXX) $(CXXFLAGS) textoSDL.cpp -o textoSDL.o

doc:
	doxygen

clean:
	$(RM) *.o
	$(RM) $(EXECUTABLES)