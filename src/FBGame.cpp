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
    SDLGraphics::initialize();
    assignGaps();
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
    assignGaps();
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
    SDLGraphics::drawQuad(1.0, 0.5, 0.4, -9, 10, -5, -15, -4.9);
    SDLGraphics::drawQuad(0, 0.6, 0, -9, 10, -5, -5.2, -4.89);
    SDLGraphics::drawQuad(0.1, 0.7, 0.1, -9, 10, -4.8, -8, -5.99);
}

void FBGame::render() {
    SDLGraphics::renderLoop();
    player.draw();
    drawBackground();
    checkForCollision(pipes);
    moveAvailableGameObjects();
}
