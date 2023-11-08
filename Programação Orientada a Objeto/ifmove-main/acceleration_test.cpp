#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "window.h"

using namespace std;

#define WIDTH 1200
#define HEIGHT 800

int main()
{
    // Inicialização do SDL
    SDL_Init(SDL_INIT_VIDEO);
    // Inicialização da biblioteca SDL_ttf para renderizar texto
    TTF_Init();

    // Criação da janela usando sua classe Window
    Window window(WIDTH, HEIGHT);

    // Carrega uma fonte TTF (TrueType Font)
    TTF_Font* font = TTF_OpenFont("arial_bold.ttf", 20);

    // Define a cor do texto
    SDL_Color textColor = { 255, 255, 255 };

    // Renderiza o texto em uma superfície (SDL_Surface)
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "giovani + chatGPT = talvez eu consiga fazer o projeto final", textColor);

    // Cria uma textura (SDL_Texture) a partir da superfície de texto
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(window.renderer, textSurface);
    
    // Define a posição e tamanho do texto na janela
    SDL_Rect textRect = { 0, 0, textSurface->w, textSurface->h };

    // Variável de controle para sair do loop principal
    bool quit = false;
    // Evento do SDL
    SDL_Event e;

    // Loop principal
    while (!quit)
    {
        // Manipula eventos do SDL
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                quit = true;
            if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_q)
                    quit = true;
            }
        }

        // Limpa o renderer
        window.clear();

        // Renderiza a textura do texto no renderer
        SDL_RenderCopy(window.renderer, textTexture, NULL, &textRect);

        // Atualiza a janela
        window.update();
    }

    // Limpeza e encerramento
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
    TTF_CloseFont(font);

    return 0;
}
