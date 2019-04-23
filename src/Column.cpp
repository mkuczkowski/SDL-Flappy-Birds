#include "Column.h"
#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

Column::Column() {}

Column::Column(float leftX, float rightX, float topY, float bottomY) {
    setLeftX(leftX);
    setRightX(rightX);
    setTopY(topY);
    setBottomY(bottomY);
}

Column::~Column() {}

void Column::setVertices(float leftX, float rightX, float topY, float bottomY) {
    setLeftX(leftX);
    setRightX(rightX);
    setTopY(topY);
    setBottomY(bottomY);
}

void Column::draw() {
    /* main */
    glColor3f(0.2, 1.0, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(getLeftX() - moveSpeed, getTopY(), -5.0);
        glVertex3f(getRightX() - moveSpeed, getTopY(), -5.0);
        glVertex3f(getRightX() - moveSpeed, getBottomY(), -5.0);
        glVertex3f(getLeftX() - moveSpeed, getBottomY(), -5.0);
    glEnd();

    /* left-side */
    glColor3f(0.5, 0.9, 0.5);
    glBegin(GL_QUADS);
        glVertex3f(getLeftX() - 0.5 - moveSpeed, getTopY() + 0.3, -5.0);
        glVertex3f(getLeftX() - moveSpeed, getTopY(), -5.0);
        glVertex3f(getLeftX() - 0.5 - moveSpeed, getBottomY() + 0.3, -5.0);
        glVertex3f(getLeftX() - moveSpeed, getBottomY(), -5.0);
    glEnd();

    /* top */
    glColor3f(0.3, 0.8, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(getLeftX() - 0.5 - moveSpeed, getTopY() + 0.3, -5.0);
        glVertex3f(getLeftX() - moveSpeed, getTopY(), -5.0);
        glVertex3f(getLeftX() - 0.5 - moveSpeed + 2, getTopY() + 0.3, -5.0);
        glVertex3f(getLeftX() - moveSpeed + 2, getTopY(), -5.0);
    glEnd();
}

float Column::getMoveSpeed() { return moveSpeed; }

void Column::setMoveSpeed(float moveSpeed) {
    this->moveSpeed = moveSpeed;
}
