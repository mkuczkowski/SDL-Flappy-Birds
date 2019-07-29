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
    FBGame* game = new FBGame();
    game->start();

    return 0;
}
