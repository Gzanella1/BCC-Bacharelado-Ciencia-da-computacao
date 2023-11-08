#include "TextoSDL.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

// Construtor da classe SDLApplication
TextoSDL::TextoSDL(const char* title, int width, int height)
    : window(nullptr), renderer(nullptr), font(nullptr), textTexture(nullptr) {
    // Inicialização do SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Criação da janela SDL
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Criação do renderer para desenhar na janela
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Carrega uma fonte TTF
    font = TTF_OpenFont("arial_bold.ttf", 20);
    if (font == nullptr) {
        std::cerr << "TTF_OpenFont error: " << TTF_GetError() << std::endl;
        exit(1);
    }

    // Configura a cor do texto
    textColor = {255, 255, 255};

    // Carrega o texto
    loadText("giovani");
}

// Destrutor da classe TextoSDL
TextoSDL::~TextoSDL() {
    cleanup();
}

// Método que inicia o loop principal da aplicação
void TextoSDL::run() {
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_q) {
                    quit = true;
                }
            }
        }

        // Renderiza a cena
        render();
    }
}

// Método para limpar recursos e encerrar o SDL
void TextoSDL::cleanup() {
    if (textTexture != nullptr) {
        SDL_DestroyTexture(textTexture);
    }
    if (font != nullptr) {
        TTF_CloseFont(font);
    }
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
    TTF_Quit();
    SDL_Quit();
}

// Método para carregar o texto e criar a textura
void TextoSDL::loadText(const char* text) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == nullptr) {
        std::cerr << "TTF_RenderText_Solid error: " << TTF_GetError() << std::endl;
        exit(1);
    }
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
}

// Método para renderizar a cena
void TextoSDL::render() {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, textTexture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}
