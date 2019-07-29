#include "Column.h"
#include "Pipe.h"
#include "Player.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "FBGame.h"

FBGame::FBGame() {
    this->isOver = false;
    this->moveSpeed = 1.0;
    this->distanceBetweenPipes = 3.9;
    this->SDLGraphics::initialize();
    this->assignGaps();
}

FBGame::~FBGame() { }

float FBGame::getRandomValue(float minValue, float maxValue) {
    return minValue + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxValue-minValue)));
}

void FBGame::assignGaps() {
    for(int i = 0; i < 100; i++) {
        this->pipes[i].setVerticalDistanceBetween(getRandomValue(1.0, 1.9));
        this->pipes[i].setupColumns(i * distanceBetweenPipes);
        this->pipes[i].setHeight(getRandomValue(-1.5, 3.5));
        this->pipes[i].assignHeightToColumns();
    }
}

void FBGame::gameOver() {
    glClearColor(1.0, 0.0, 0.0, 1.0);
    this->isOver = true;
}

void FBGame::restart() {
    this->player.setPositionY(1.0);
    this->moveSpeed = 1.0;
    this->player.setFallVelocity(0.0015);
    this->isOver = false;
    glClearColor(0.1, 0.8, 1.0, 1.0);
    this->assignGaps();
}

void FBGame::checkForCollisions() {
    for(int i = 0; i < 100; i++) {
        this->pipes[i].drawColumns(this->moveSpeed);
        if((pipes[i].getBottom().getLeftX() - moveSpeed < player.getRightX() && pipes[i].getBottom().getRightX() - moveSpeed > player.getRightX())
        && (player.getBottomY() + player.getPositionY() < pipes[i].getBottom().getTopY() || player.getTopY() + player.getPositionY() > pipes[i].getTop().getBottomY())) {
            this->gameOver();
        }
    }
}

void FBGame::moveAvailableGameObjects() {
    if(!this->isOver) {
        float newPlayerPosition = this->player.getPositionY() - this->player.getFallVelocity();
        this->player.setPositionY(newPlayerPosition);
        this->moveSpeed += 0.0015;
        for(int i = 0; i < 100; i++) {
            this->pipes[i].moveVertically();
            this->pipes[i].setupColumns(i * this->distanceBetweenPipes);
            this->pipes[i].assignHeightToColumns();
        }
    }
}

void FBGame::drawBackground() {
    SDLGraphics::drawQuad(1.0, 0.5, 0.4, -9, 10, -5, -15, -4.9);
    SDLGraphics::drawQuad(0, 0.6, 0, -9, 10, -5, -5.2, -4.89);
    SDLGraphics::drawQuad(0.1, 0.7, 0.1, -9, 10, -4.8, -8, -5.99);
}

void FBGame::render() {
    this->SDLGraphics::renderLoop();
    this->player.draw();
    this->drawBackground();
    this->checkForCollisions();
    this->moveAvailableGameObjects();
    SDL_GL_SwapBuffers();
}

void FBGame::quit() { SDL_Quit(); }

void FBGame::start() {
    while (true) {
        while (SDL_PollEvent(&this->event)) {
            switch((&this->event)->type) {
                case SDL_KEYDOWN:
                    if((&this->event)->key.keysym.sym == SDLK_SPACE && !this->isOver)
                        this->player.jump();
                    if((&this->event)->key.keysym.sym == SDLK_r)
                        this->restart();
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if ((&this->event)->button.button == SDL_BUTTON_LEFT && !this->isOver)
                        this->player.jump();
                    break;
                case SDL_QUIT:
                    this->quit();
                    return;
                    break;
            }
        }
        this->render();
    }
}
