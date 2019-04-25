#include "SDLGraphics.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

SDLGraphics::SDLGraphics() {}

SDLGraphics::~SDLGraphics() {}

void SDLGraphics::initialize() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE | SDL_OPENGL);
    glClearColor(0.1, 0.8, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 640.0/480.0, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void SDLGraphics::drawQuad( float red, float green, float blue,
                            float left, float right, float top, float bottom, float z ) {
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
        glVertex3f(left, top, z);
        glVertex3f(right, top, z);
        glVertex3f(right, bottom, z);
        glVertex3f(left, bottom, z);
    glEnd();
}

void SDLGraphics::drawPreciseQuad(float red, float green, float blue,
                    float topLeft, float topRight, float leftTop, float rightTop,
                    float bottomRight, float bottomLeft, float rightBottom, float leftBottom, float z ) {
    glColor3f(red, green, blue);
    glBegin(GL_QUADS);
        glVertex3f(topLeft, leftTop, z);
        glVertex3f(topRight, rightTop, z);
        glVertex3f(bottomRight, rightBottom, z);
        glVertex3f(bottomLeft, leftBottom, z);
    glEnd();
}

void SDLGraphics::renderLoop() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1, 0, -5);
}
