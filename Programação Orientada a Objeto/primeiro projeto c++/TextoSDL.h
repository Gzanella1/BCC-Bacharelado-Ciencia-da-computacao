#ifndef TextoSDL_H
#define TextoSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class TextoSDL {
public:
    // Construtor da classe TextoSDL, recebe o título da janela, largura e altura
    TextoSDL(const char* title, int width, int height);
    
    // Destrutor da classe TextoSDL
    ~TextoSDL();
    
    // Método que inicia o loop principal da aplicação
    void run();

private:
    SDL_Window* window;       // Ponteiro para a janela SDL
    SDL_Renderer* renderer;   // Ponteiro para o renderer SDL
    TTF_Font* font;           // Ponteiro para a fonte TTF
    SDL_Color textColor;      // Cor do texto
    SDL_Texture* textTexture; // Textura do texto

    // Método para limpar recursos e encerrar o SDL
    void cleanup();

    // Método para carregar o texto e criar a textura
    void loadText(const char* text);

    // Método para renderizar a cena
    void render();
};

#endif // SDLAPPLICATION_H
