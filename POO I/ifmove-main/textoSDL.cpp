#include "TextoSDL.h"

TextoSDL::TextoSDL(SDL_Window* window, TTF_Font* font, SDL_Color textColor=SDL_Color{255,255,255,255},SDL_Texture* textTexture)
:window(window),font(font),textColor(textColor),textTexture(textTexture) {
    font = TTF_OpenFont("arial.ttf", 250); 
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "surface", textColor);
}


TextoSDL::~TextoSDL()
{
    TTF_CloseFont(font);
}


void TextoSDL::loadText(char *text, SDL_Renderer *renderer)
{
    if (textTexture != nullptr)
    {
        SDL_DestroyTexture(textTexture);
        textTexture = nullptr;
    }

    textSurface = TTF_RenderText_Solid(font, text, textColor);
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
    SDL_Rect textRect = {110, 110, textSurface->w, textSurface->h};
    // Renderiza a textura do texto no renderer
    SDL_RenderCopy(w.renderer, textTexture, NULL, &textRect);
}
















// #ifndef TextoSDL_H
// #define TextoSDL_H

// #include "window.h"
// #include <SDL2/SDL_ttf.h>
// #include <SDL2/SDL.h>

// // class TextoSDL {
// public:
//     // Construtor da classe TextoSDL, recebe o título da janela, largura e altura
//     TextoSDL(const char* title, int width, int height, int x, int y);
    
//     // Destrutor da classe TextoSDL
//     ~TextoSDL();
    
//     void draw(Window w);

// private:
//     string title;
//     //esta dando erro aqui SDL_Window; 
//     //SDL_Window* TextoSDL;    // Ponteiro para a janela SDL
//     SDL_Window* window;      
//     SDL_Renderer* renderer;  // Ponteiro para o renderer SDL
//     TTF_Font* font;          // Ponteiro para a fonte TTF
//     SDL_Color textColor;     // Cor do texto
//     SDL_Texture* textTexture; // Textura do texto

//     // Método para carregar o texto e criar a textura
//     void loadText(const char* text);
   
    
// };

// #endif // SDLAPPLICATION_H



// #include <SDL2/SDL_ttf.h>
// #include <SDL2/SDL.h>
// #include "textoSDL.h"

// class TextoSDL
// {
//     TextoSDL::TextoSDL(const char *title, int width, int height, int x, int y) : title{title},
//                                                                                  width{width},
//                                                                                  height{height},
//                                                                                  x{x},
//                                                                                  y{y}
//     {
//         font = TTF_OpenFont("arial.ttf", 250);
//         // Define a cor do texto
//         textColor = {255, 255, 255};
//         SDL_Surface *textSurface = TTF_RenderText_Solid(font, title, textColor);
//         if (textTexture != null)
//             SDL_DestroyTexture(textTexture);
//     }

//     TextoSDL::~TextoSDL()
//     {
//         TTF_CloseFont(font);
//     }

//     void TextoSDL::render()
//     {
//     }

//     void TextoSDL::loadText(char *text, SDL_Renderer *renderer)
//     {
//         if (textTexture != nullptr)
//         {
//             SDL_DestroyTexture(textTexture);
//             textTexture = nullptr;
//         }

//         SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
//         if (textSurface == nullptr)
//         {
//             cerr << "Error creating text surface: " << TTF_GetError() << endl;
//             return;
//         }

//         textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//         SDL_FreeSurface(textSurface);
//     }

//     void TextoSDL::draw(Window w)
//     {
//         if (textTexture == nullptr)
//             textTexture = SDL_CreateTextureFromSurface(w.renderer, textSurface);
//         // Define a posição e tamanho do texto na janela
//         SDL_Rect textRect = {x, y, width, height};
//         // Renderiza a textura do texto no renderer
//         SDL_RenderCopy(window.renderer, textTexture, NULL, &textRect);
//     }
// }
