#include "Column.h"
#include "Pipe.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "FBGame.h"

FBGame::FBGame() {
    isOver = false;
    moveSpeed = 1.0;
    playerPosY = 1.0;
    playerLeftX = -1.2;
    playerRightX = -1.5;
    playerTopY = -1.2;
    playerBottomY = -1.5;
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
    glClearColor(0.1, 0.6, 0.4, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 640.0/480.0, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void FBGame::drawPlayer() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex3f(playerLeftX, playerTopY + playerPosY, -5.0);
        glVertex3f(playerRightX, playerTopY + playerPosY, -5.0);
        glVertex3f(playerRightX, playerBottomY + playerPosY, -5.0);
        glVertex3f(playerLeftX, playerBottomY + playerPosY, -5.0);
    glEnd();
}

void FBGame::gameOver() {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    isOver = true;
}

void FBGame::restart() {
    playerPosY = 1.0;
    moveSpeed = 1.0;
    isOver = false;
    glClearColor(0.1, 0.6, 0.4, 1.0);
}

void FBGame::checkForCollision(Pipe pipe[]) {
    for(int i = 0; i < 100; i++) {
        pipe[i].drawColumns(moveSpeed);
        if((pipe[i].getBottom().getLeftX() - moveSpeed < playerLeftX && pipe[i].getBottom().getRightX() - moveSpeed > playerLeftX)
        && (playerBottomY + playerPosY < pipe[i].getBottom().getTopY() || playerTopY + playerPosY > pipe[i].getTop().getBottomY())) {
            gameOver();
        }
    }
}

void FBGame::moveAvailableGameObjects() {
    if(!isOver) {
        playerPosY -= 0.0015;
        moveSpeed += 0.0015;
    }
}

void FBGame::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1, 0, -5);
    drawPlayer();
    checkForCollision(pipes);
    moveAvailableGameObjects();
}
