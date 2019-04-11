#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<iostream>

using namespace std;

float playerPosY = 1.0;

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

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1, 0, -5);
    drawPlayer();
    playerPosY -= 0.0005;
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
                    if(myevent.key.keysym.sym == SDLK_SPACE) playerPosY += 0.7;
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
