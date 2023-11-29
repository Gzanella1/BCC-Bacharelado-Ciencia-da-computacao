#ifndef TextoSDL_H
#define TextoSDL_H

#include "window.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

class TextoSDL {
public:
    // Construtor da classe TextoSDL, recebe o título da janela, largura e altura
    TextoSDL(const char* title, int width, int height, int x, int y);
    
    // Destrutor da classe TextoSDL
    ~TextoSDL();
    
    void draw(Window w);

private:
    string title;
    //esta dando erro aqui SDL_Window; 
    //SDL_Window* TextoSDL;    // Ponteiro para a janela SDL
    SDL_Window* window;      
    SDL_Renderer* renderer;  // Ponteiro para o renderer SDL
    TTF_Font* font;          // Ponteiro para a fonte TTF
    SDL_Color textColor;     // Cor do texto
    SDL_Texture* textTexture; // Textura do texto

    // Método para carregar o texto e criar a textura
    void loadText(const char* text);
   
    
};

#endif // SDLAPPLICATION_H

