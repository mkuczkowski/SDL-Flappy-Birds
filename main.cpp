#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<iostream>

using namespace std;

float playerPosY = 1.0;
float moveSpeed = 1.0;
bool isGameOver = false;

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
        glVertex3f(1.2, (-1.2) + playerPosY, -5.0);
        glVertex3f(2.2, (-1.2) + playerPosY, -5.0);
        glVertex3f(2.2, (-2.2) + playerPosY, -5.0);
        glVertex3f(1.2, (-2.2) + playerPosY, -5.0);
    glEnd();
}

void drawColumn() {
    glColor3f(0.2, 1.0, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(4.2 - moveSpeed, -1.2, -5.0);
        glVertex3f(6.2 - moveSpeed, -1.2, -5.0);
        glVertex3f(6.2 - moveSpeed, -5.2, -5.0);
        glVertex3f(4.2 - moveSpeed, -5.2, -5.0);
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1, 0, -5);
    drawPlayer();
    drawColumn();

    if(4.2 - moveSpeed < 2.2 && 6.2 - moveSpeed > 1.2 && (-2.2) + playerPosY < -1.2) {
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
        display();
        SDL_GL_SwapBuffers();
    }
    SDL_Quit();
    return 0;
}
