#include "Column.h"
#include "Pipe.h"
#include "Player.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "FBGame.h"

FBGame::FBGame() {
    isOver = false;
    moveSpeed = 1.0;
}

FBGame::~FBGame() { }

float FBGame::getRandomValue(float minValue, float maxValue) {
    return minValue + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxValue-minValue)));
}

void FBGame::assignGaps() {
    for(int i = 0; i < 100; i++) {
        pipes[i].setupColumns(getRandomValue(1.0, 1.9), i * 3.9);
        pipes[i].setHeight(getRandomValue(-1.5, 3.5));
    }
}

void FBGame::initialize() {
    glClearColor(0.1, 0.8, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 640.0/480.0, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void FBGame::gameOver() {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    isOver = true;
}

void FBGame::restart() {
    player.setPositionY(1.0);
    moveSpeed = 1.0;
    player.setFallVelocity(0.0015);
    isOver = false;
    glClearColor(0.1, 0.8, 1.0, 1.0);
}

void FBGame::checkForCollision(Pipe pipe[]) {
    for(int i = 0; i < 100; i++) {
        pipe[i].drawColumns(moveSpeed);
        if((pipe[i].getBottom().getLeftX() - moveSpeed < player.getRightX() && pipe[i].getBottom().getRightX() - moveSpeed > player.getRightX())
        && (player.getBottomY() + player.getPositionY() < pipe[i].getBottom().getTopY() || player.getTopY() + player.getPositionY() > pipe[i].getTop().getBottomY())) {
            gameOver();
        }
    }
}

void FBGame::moveAvailableGameObjects() {
    if(!isOver) {
        float newPlayerPosition = player.getPositionY() - player.getFallVelocity();
        player.setPositionY(newPlayerPosition);
        moveSpeed += 0.0015;
    }
}

void FBGame::drawBackground() {
    glColor3f(1.0, 0.5, 0.4);
    glBegin(GL_QUADS);
        glVertex3f(-9, -5, -4.9);
        glVertex3f(10, -5, -4.9);
        glVertex3f(10, -15, -4.9);
        glVertex3f(-9, -15, -4.9);
    glEnd();

    glColor3f(0.0, 0.6, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(-9, -5, -4.89);
        glVertex3f(10, -5, -4.89);
        glVertex3f(10, -5.2, -4.89);
        glVertex3f(-9, -5.2, -4.89);
    glEnd();

    glColor3f(0.1, 0.7, 0.1);
    glBegin(GL_QUADS);
        glVertex3f(-9, -4.8, -5.99);
        glVertex3f(10, -4.8, -5.99);
        glVertex3f(10, -8, -5.99);
        glVertex3f(-9, -8, -5.99);
    glEnd();
}

void FBGame::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1, 0, -5);
    player.draw();
    drawBackground();
    checkForCollision(pipes);
    moveAvailableGameObjects();
}
