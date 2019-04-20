#include "Column.h"
#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

Column::Column() {}

Column::Column(float leftX, float rightX, float topY, float bottomY) {
    this->leftX = leftX;
    this->rightX = rightX;
    this->topY = topY;
    this->bottomY = bottomY;
}

Column::~Column() {}

void Column::setVertices(float leftX, float rightX, float topY, float bottomY) {
    this->leftX = leftX;
    this->rightX = rightX;
    this->topY = topY;
    this->bottomY = bottomY;
}

void Column::drawColumn(float moveSpeed) {
    /* main */
    glColor3f(0.2, 1.0, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(leftX - moveSpeed, topY, -5.0);
        glVertex3f(rightX - moveSpeed, topY, -5.0);
        glVertex3f(rightX - moveSpeed, bottomY, -5.0);
        glVertex3f(leftX - moveSpeed, bottomY, -5.0);
    glEnd();

    /* left-side */
    glColor3f(0.5, 0.9, 0.5);
    glBegin(GL_QUADS);
        glVertex3f(leftX - 0.5 - moveSpeed, topY + 0.3, -5.0);
        glVertex3f(leftX - moveSpeed, topY, -5.0);
        glVertex3f(leftX - 0.5 - moveSpeed, bottomY + 0.3, -5.0);
        glVertex3f(leftX - moveSpeed, bottomY, -5.0);
    glEnd();

    /* top */
    glColor3f(0.3, 0.8, 0.3);
    glBegin(GL_QUADS);
        glVertex3f(leftX - 0.5 - moveSpeed, topY + 0.3, -5.0);
        glVertex3f(leftX - moveSpeed, topY, -5.0);
        glVertex3f(leftX - 0.5 - moveSpeed + 2, topY + 0.3, -5.0);
        glVertex3f(leftX - moveSpeed + 2, topY, -5.0);
    glEnd();
}

float Column::getLeftX() { return leftX; }

float Column::getRightX() { return rightX; }

float Column::getBottomY() { return bottomY; }

float Column::getTopY() { return topY; }
