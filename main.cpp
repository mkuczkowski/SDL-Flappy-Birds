#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include "Column.h"
#include "Pipe.h"

float playerPosY = 1.0;
float moveSpeed = 1.0;
bool isGameOver = false;
const float PLAYER_LEFT_X = 1.2;
const float PLAYER_RIGHT_X = 2.2;
const float PLAYER_TOP_Y = -1.2;
const float PLAYER_BOTTOM_Y = -2.2;

void init() {
    glClearColor(0.1, 0.6, 0.4, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 640.0/480.0, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void drawPlayer() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(PLAYER_LEFT_X, PLAYER_TOP_Y + playerPosY, -5.0);
        glVertex3f(PLAYER_RIGHT_X, PLAYER_TOP_Y + playerPosY, -5.0);
        glVertex3f(PLAYER_RIGHT_X, PLAYER_BOTTOM_Y + playerPosY, -5.0);
        glVertex3f(PLAYER_LEFT_X, PLAYER_BOTTOM_Y + playerPosY, -5.0);
    glEnd();
}

void gameOver() {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    isGameOver = true;
}

void restartGame() {
    playerPosY = 1.0;
    moveSpeed = 1.0;
    isGameOver = false;
    glClearColor(0.1, 0.6, 0.4, 1.0);
}

void display(Pipe &pipe) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1, 0, -5);
    drawPlayer();
    pipe.drawColumns(moveSpeed);
    if((pipe.bottom.leftX - moveSpeed < PLAYER_RIGHT_X && pipe.bottom.rightX - moveSpeed > PLAYER_LEFT_X)
    && (PLAYER_BOTTOM_Y + playerPosY < pipe.bottom.topY || PLAYER_TOP_Y + playerPosY > pipe.top.bottomY)) {
        gameOver();
    } else {
        playerPosY -= 0.0005;
        moveSpeed += 0.0005;
    }
}

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_OPENGL);
    SDL_Event myevent;
    init();
    Pipe pipe(1.5);
    while (true) {
        while (SDL_PollEvent(&myevent)) {
            switch(myevent.type) {
                case SDL_KEYDOWN:
                    if(myevent.key.keysym.sym == SDLK_SPACE && !isGameOver) playerPosY += 0.7;
                    if(myevent.key.keysym.sym == SDLK_r) restartGame();
                    break;
                case SDL_QUIT:
                    return 0;
                    break;
            }
        }
        display(pipe);
        SDL_GL_SwapBuffers();
    }
    SDL_Quit();
    return 0;
}
