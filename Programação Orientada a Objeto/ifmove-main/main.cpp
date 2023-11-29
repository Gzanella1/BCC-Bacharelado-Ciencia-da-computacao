#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "window.h"
#include "textoSDL.h"

using namespace std;


int main()
{
    private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int width;
    int height;

    // Cria uma janela
    Window window(WIDTH, HEIGHT);

    // Inicializa a janela
    window.init();

    // Renderiza o texto
    window.renderText("Eder me passa Pls", { 255, 255, 255 }, 100, 200);

    // Atualiza a janela
    window.update();

    // Espera o usuário fechar a janela
    while (true)
    {
        SDL_Event e;
        if (SDL_WaitEvent(&e) == 0)
            break;

        if (e.type == SDL_QUIT)
            break;
    }

    // Fecha a janela
    window.close();

    return 0;
}
