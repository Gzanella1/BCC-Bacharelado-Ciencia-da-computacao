.PHONY: all clean doc

CXX=c++
CXXFLAGS = -g -I/path/to/SDL/header/files $(shell pkg-config --cflags SDL2 SDL2_ttf)
SDL_LIBS = $(shell pkg-config --libs SDL2 SDL2_ttf)
EXECUTABLES = main

all: $(EXECUTABLES)


main: main.cpp 
	$(CXX) $(CXXFLAGS) main.cpp  -o main $(SDL_LIBS)

doc:
	doxygen

clean:
	$(RM) *.o
	$(RM) $(EXECUTABLES)



