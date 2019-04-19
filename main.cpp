#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Column.h"
#include "Pipe.h"
#include "FBGame.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char* args[]) {
    srand (static_cast <unsigned> (time(0)));
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_OPENGL);
    SDL_Event event;
    FBGame game;
    game.initialize();
    game.assignGaps();
    while (true) {
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_SPACE && !game.isOver)
                        game.playerPosY += game.getJumpHeight();
                    if(event.key.keysym.sym == SDLK_r) {
                        game.assignGaps();
                        game.restart();
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT && !game.isOver)
                        game.playerPosY += game.getJumpHeight();
                    break;
                case SDL_QUIT:
                    return 0;
                    break;
            }
        }
        game.render();
        SDL_GL_SwapBuffers();
    }
    SDL_Quit();
    return 0;
}
