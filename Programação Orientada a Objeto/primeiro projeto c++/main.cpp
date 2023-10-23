#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    // Inicialize a SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("Erro ao inicializar a SDL: %s", SDL_GetError());
        return 1;
    }

    // Crie uma janela
    SDL_Window* window = SDL_CreateWindow("Minha Janela SDL", 
                                          SDL_WINDOWPOS_UNDEFINED, 
                                          SDL_WINDOWPOS_UNDEFINED, 
                                          640, 480, 
                                          SDL_WINDOW_SHOWN);

    if (!window) {
        SDL_Log("Erro ao criar a janela: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Mantenha a janela aberta por alguns segundos (nesse caso, 5 segundos)
    SDL_Delay(5000);

    // Libere recursos e feche a SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
