#include "Player.h"
#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

Player::Player() {
    positionY = 1.0;
    leftX = -1.2;
    rightX = -1.5;
    topY = -1.2;
    bottomY = -1.5;
    jumpHeight = 0.8;
    fallVelocity = 0.0015;
}

Player::~Player() {}

void Player::draw() {
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(leftX, topY + positionY, -5.0);
        glVertex3f(rightX, topY + positionY, -5.0);
        glVertex3f(rightX, bottomY + positionY, -5.0);
        glVertex3f(leftX, bottomY + positionY, -5.0);
    glEnd();
    fallVelocity += 0.000003;
}

void Player::jump() {
    fallVelocity = 0.0015;
    positionY += jumpHeight;
}

float Player::getLeftX() { return leftX; }

float Player::getRightX() { return rightX; }

float Player::getBottomY() { return bottomY; }

float Player::getTopY() { return topY; }

float Player::getPositionY() { return positionY; }

float Player::getFallVelocity() { return fallVelocity; }

void Player::setFallVelocity(float velocity) {
    fallVelocity = velocity;
}

void Player::setPositionY(float position) {
    positionY = position;
}
