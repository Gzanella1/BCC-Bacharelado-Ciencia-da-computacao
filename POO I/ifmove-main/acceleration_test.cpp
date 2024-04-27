#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "window.h"
#include "textoSDL.h"

using namespace std;

#define WIDTH 1200
#define HEIGHT 800

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "window.h"
#include "textoSDL.h"



int main()
{
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    // Inicializar SDL_ttf
    if (TTF_Init() < 0)
    {
        cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
        return 1;
    }

    // Criar uma janela
    Window window(800, 600);

    // Criar um objeto TextoSDL
    TextoSDL texto(window.window);

    // Carregar texto no objeto TextoSDL
    texto.loadText("Hello, SDL!");//window.renderer

    // Loop principal
    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        // Processar eventos
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Limpar a tela
        window.clear();

        // Renderizar e desenhar o texto
        //texto.render(window.renderer);
        texto.draw(window);

        // Atualizar a janela
        window.update();
    }

    // Finalizar SDL_ttf
    TTF_Quit();

    // Finalizar SDL
    SDL_Quit();

    return 0;
}
