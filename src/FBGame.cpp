#include "Column.h"
#include "Pipe.h"
#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include "FBGame.h"

FBGame::FBGame() {
    isOver = false;
    moveSpeed = 1.0;
    playerPosY = 1.0;
    playerLeftX = 1.2;
    playerRightX = 2.2;
    playerTopY = -1.2;
    playerBottomY = -2.2;
    pipe.setupColumns(1.5);
}

FBGame::~FBGame() { }

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

void FBGame::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1, 0, -5);
    drawPlayer();
    pipe.drawColumns(moveSpeed);
    if((pipe.bottom.leftX - moveSpeed < playerRightX && pipe.bottom.rightX - moveSpeed > playerLeftX)
    && (playerBottomY + playerPosY < pipe.bottom.topY || playerTopY + playerPosY > pipe.top.bottomY)) {
        gameOver();
    } else {
        playerPosY -= 0.0005;
        moveSpeed += 0.0005;
    }
}
