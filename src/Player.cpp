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
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(getLeftX(), getTopY() + positionY, -5.0);
        glVertex3f(getRightX(), getTopY() + positionY, -5.0);
        glVertex3f(getRightX(), getBottomY() + positionY, -5.0);
        glVertex3f(getLeftX(), getBottomY() + positionY, -5.0);
    glEnd();

    glColor3f(0.8, 0.8, 0.5);
    glBegin(GL_QUADS);
        glVertex3f(getLeftX() - 0.15, getTopY() + positionY + 0.1, -5.0);
        glVertex3f(getLeftX(), getTopY() + positionY, -5.0);
        glVertex3f(getLeftX(), getBottomY() + positionY, -5.0);
        glVertex3f(getLeftX() - 0.15, getBottomY() + positionY  + 0.1, -5.0);
    glEnd();

    glColor3f(0.9, 0.9, 0.5);
    glBegin(GL_QUADS);
        glVertex3f(getLeftX() - 0.15, getTopY() + positionY + 0.1, -5.0);
        glVertex3f(getRightX() - 0.15, getTopY() + positionY + 0.1, -5.0);
        glVertex3f(getRightX(), getTopY() + positionY, -5.0);
        glVertex3f(getLeftX(), getTopY() + positionY , -5.0);
    glEnd();

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
