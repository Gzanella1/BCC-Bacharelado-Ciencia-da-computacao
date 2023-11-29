#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include "textoSDL.h"

class TextoSDL
{
    TextoSDL::TextoSDL(const char *title, int width, int height, int x, int y) : title{title},
                                                                                 width{width},
                                                                                 height{height},
                                                                                 x{x},
                                                                                 y{y}
    {
        font = TTF_OpenFont("arial.ttf", 250);
        // Define a cor do texto
        textColor = {255, 255, 255};
        SDL_Surface *textSurface = TTF_RenderText_Solid(font, title, textColor);
        if (textTexture != null)
            SDL_DestroyTexture(textTexture);
    }

    TextoSDL::~TextoSDL()
    {
        TTF_CloseFont(font);
    }

    void TextoSDL::render()
    {
    }

    void TextoSDL::loadText(char *text, SDL_Renderer *renderer)
    {
        if (textTexture != nullptr)
        {
            SDL_DestroyTexture(textTexture);
            textTexture = nullptr;
        }

        SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
        if (textSurface == nullptr)
        {
            cerr << "Error creating text surface: " << TTF_GetError() << endl;
            return;
        }

        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
    }

    void TextoSDL::draw(Window w)
    {
        if (textTexture == nullptr)
            textTexture = SDL_CreateTextureFromSurface(w.renderer, textSurface);
        // Define a posição e tamanho do texto na janela
        SDL_Rect textRect = {x, y, width, height};
        // Renderiza a textura do texto no renderer
        SDL_RenderCopy(window.renderer, textTexture, NULL, &textRect);
    }
}
