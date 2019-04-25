#include "Player.h"
#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

Player::Player() {
    positionY = 1.0;
    setLeftX(-1.5);
    setRightX(-1.2);
    setTopY(-1.2);
    setBottomY(-1.5);
    jumpHeight = 0.8;
    fallVelocity = 0.0015;
}

Player::~Player() {}

void Player::draw() {
    SDLGraphics::drawQuad(1, 1, 0, getLeftX(), getRightX(), getTopY() + positionY, getBottomY() + positionY, -5);
    SDLGraphics::drawPreciseQuad(0.8, 0.8, 0.5, getLeftX() - 0.15, getLeftX(), getTopY() + positionY + 0.1,
                    getTopY() + positionY, getLeftX(), getLeftX() - 0.15, getBottomY() + positionY, getBottomY() + positionY + 0.1, -5);
    SDLGraphics::drawPreciseQuad(0.9, 0.9, 0.5, getLeftX() - 0.15, getRightX() - 0.15, getTopY() + positionY + 0.1,
                    getTopY() + positionY + 0.1, getRightX(), getLeftX(), getTopY() + positionY, getTopY() + positionY, -5);
    fallVelocity += 0.000003;
}

void Player::jump() {
    fallVelocity = 0.0015;
    positionY += jumpHeight;
}

float Player::getPositionY() { return positionY; }

float Player::getFallVelocity() { return fallVelocity; }

void Player::setFallVelocity(float velocity) {
    this->fallVelocity = velocity;
}

void Player::setPositionY(float position) {
    this->positionY = position;
}
