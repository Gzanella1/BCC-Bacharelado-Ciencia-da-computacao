#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "textoSDL.h"

using namespace std;

int main()
{
    // Cria uma instância da classe SDLApplication com título "SDL Text" e dimensões da janela 800x600
    TextoSDL app("SDL Text", 800, 600);
    // Inicia a execução da aplicação
    app.run();

    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}
