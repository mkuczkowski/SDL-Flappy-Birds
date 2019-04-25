#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Column.h"
#include "Pipe.h"
#include "Player.h"
#include "FBGame.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char* args[]) {
    srand (static_cast <unsigned> (time(0)));
    FBGame game;
    while (true) {
        while (SDL_PollEvent(game.getEvent())) {
            switch(game.getEvent()->type) {
                case SDL_KEYDOWN:
                    if(game.getEvent()->key.keysym.sym == SDLK_SPACE && !game.isOver)
                        game.player.jump();
                    if(game.getEvent()->key.keysym.sym == SDLK_r) {
                        game.restart();
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (game.getEvent()->button.button == SDL_BUTTON_LEFT && !game.isOver)
                        game.player.jump();
                    break;
                case SDL_QUIT:
                    game.quit();
                    return 0;
                    break;
            }
        }
        game.render();
    }
    game.quit();
    return 0;
}
