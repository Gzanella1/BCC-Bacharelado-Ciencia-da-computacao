#ifndef TextoSDL_H
#define TextoSDL_H
#include<string>
#include "window.h"
#include <SDL2/SDL_ttf.h>

class TextoSDL {
public:
    // Construtor daco classe TextoSDL, recebe o título da janela, largura e altura

    TextoSDL(SDL_Window* window, TTF_Font* font = nullptr, 
             SDL_Color textColor = {255, 255, 255, 255}, SDL_Texture* textTexture = nullptr);

    // Destrutor da classe TextoSDL
    ~TextoSDL();
    void draw(Window w);
    void loadText(const char* text);

private:

    //esta dando erro aqui SDL_Window; 
    //SDL_Window* TextoSDL;    // Ponteiro para a janela SDL
    SDL_Window* window;      
    TTF_Font* font;          // Ponteiro para a fonte TTF
    SDL_Color textColor;     // Cor do texto
    SDL_Texture* textTexture; // Textura do texto
    SDL_Surface *textSurface ;

    // Método para carregar o texto e criar a textura
   
    
};

#endif // SDLAPPLICATION_H







