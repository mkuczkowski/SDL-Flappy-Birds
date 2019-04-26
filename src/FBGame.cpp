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
    distanceBetweenPipes = 3.9;
    SDLGraphics::initialize();
    assignGaps();
}

FBGame::~FBGame() { }

float FBGame::getRandomValue(float minValue, float maxValue) {
    return minValue + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxValue-minValue)));
}

void FBGame::assignGaps() {
    for(int i = 0; i < 100; i++) {
        pipes[i].setVerticalDistanceBetween(getRandomValue(1.0, 1.9));
        pipes[i].setupColumns(i * distanceBetweenPipes);
        pipes[i].setHeight(getRandomValue(-1.5, 3.5));
        pipes[i].assignHeightToColumns();
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

void FBGame::checkForCollisions() {
    for(int i = 0; i < 100; i++) {
        pipes[i].drawColumns(moveSpeed);
        if((pipes[i].getBottom().getLeftX() - moveSpeed < player.getRightX() && pipes[i].getBottom().getRightX() - moveSpeed > player.getRightX())
        && (player.getBottomY() + player.getPositionY() < pipes[i].getBottom().getTopY() || player.getTopY() + player.getPositionY() > pipes[i].getTop().getBottomY())) {
            gameOver();
        }
    }
}

void FBGame::moveAvailableGameObjects() {
    if(!isOver) {
        float newPlayerPosition = player.getPositionY() - player.getFallVelocity();
        player.setPositionY(newPlayerPosition);
        moveSpeed += 0.0015;
        for(int i = 0; i < 100; i++) {
            pipes[i].moveVertically();
            pipes[i].setupColumns(i * distanceBetweenPipes);
            pipes[i].assignHeightToColumns();
        }
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
    checkForCollisions();
    moveAvailableGameObjects();
    SDL_GL_SwapBuffers();
}

SDL_Event* FBGame::getEvent() { return &event; }

void FBGame::quit() { SDL_Quit(); }
