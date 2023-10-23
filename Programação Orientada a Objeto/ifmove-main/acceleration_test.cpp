#include <cmath>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

using namespace std;

#include "window.h"
#include "sdl.h"
#include "gcircle.h"
#include "gsquare.h"
#include "grid.h"
#include "gparticle.h"
#include "gtriangle.h"

#define WIDTH 1200
#define HEIGHT 800

int main()
{
    Window w(WIDTH, HEIGHT);
    // create a SDL object
    SDL sdl;
    // quit will control the main loop (game loop)
    bool quit = false;

    // Event handler, it'll handle keyboard and mouse events
    SDL_Event e;

    double angle = 0.0;
    double t = 0;
    double t0 = 0;
    double dt = 1.0/1000.0;
    double k = 0; 

    TTF_Init();
    //definindo tipo e tamanho 
    TTF_Font *font= TTF_OpenFont("arial/arial.ttf",20);
    //define cor da font4e
    SDL_Color corFont= {255,255,255};
    //define cor do fundo 
    SDL_Color corFundo={255,0,0};
    SDL_Surface *texto = TTF_RenderText_Shaded(font,"giovani",corFont,corFundo);
    SDL_Rect localtexto = {100,100,0,0};
    SDL_BlitSurface(texto, NULL, w.screenSurface, &localtexto);


    Grid grid{Vector3<double>{}, WIDTH-200, HEIGHT-200, 100, 100,
        RGBA<unsigned char>{0xff, 0xff, 0xff, 0x30}
    };

    GSquare square{Vector3<double>{50, 50, 1.0f}, 75, 
        RGBA<unsigned char>{0xff, 0xff, 0x0, 0x99}};

    GTriangle triangle{
        Vector3<double>{0, 0, 1.0f}, 
        Vector3<double>{-150, -50, 1.0f}, 
        Vector3<double>{+150, -50, 1.0f} };

    GParticle particle{
        Vector3<double>{-350, -0, 1.0f},
        Vector3<double>{0.0, 0.0, 0.0f},
        Vector3<double>{0.0, 0.0, 0.0f}, 
        50.0
    };

    vector<Graphics *> graphics;
    graphics.push_back(&grid);
    graphics.push_back(&particle);
    graphics.push_back(&square);
    graphics.push_back(&triangle);
    
        Matrix<double> transform = w.transform();
        transform.a[0][0] = 0.50;
        transform.a[1][1] = 0.50 * -1 * transform.a[1][1];
        transform.a[0][2] = WIDTH/2;
        transform.a[1][2] = HEIGHT/2;
        
        w.transform(transform);
        // main loop
        while (!quit) 
        {
            // Handle events on event queue
            while(SDL_PollEvent(&e) != 0)
            {
                // User requests quit
                if(e.type == SDL_QUIT)
                    quit = true;
                // Keydown Event
                if(e.type == SDL_KEYDOWN)
                {       
                    // pressing q will exit the main loop
                    if (e.key.keysym.sym == SDLK_q)
                        quit = true;
                    if (e.key.keysym.sym == SDLK_a)
                    {
                        k = 1;
                        t0 = t;
                    }
                }
            }
            
            // clear surface before draw
            w.clear();           
            // control rotation speed of line
            angle += 0.003;
            /*
            gcircle.draw(w);
            gcircle.transform(translate);*/

            particle.a.a[0][0] = k*100*exp(-(t-t0));
            cout << particle << endl;
            particle.move(dt);

            for (size_t i = 0; i < graphics.size(); i++)
                graphics[i]->draw(w);

            // update renderer
            w.update();
            if ( abs(particle.v.y() - 0) < 1.0/10000 )
                cout << "t = " << t << endl; 
            t += dt;
        } // end of main loop
        SDL_FreeSurface(texto);
        SDL_blit(w.screenSurface);
        TTF_CloseFont(font);
    
        TTF_Quit();
        SDL_Quit();
    // return no error to the operating system
    return 0;
}