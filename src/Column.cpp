#include "Column.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

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
    SDLGraphics::drawQuad(0.2, 1, 0.3, getLeftX() - moveSpeed, getRightX() - moveSpeed, getTopY(), getBottomY(), -5);

    /* left-side */
    SDLGraphics::drawPreciseQuad(0.5, 0.9, 0.5, getLeftX() - 0.5 - moveSpeed, getLeftX() - moveSpeed, getTopY() + 0.3, getTopY(),
                    getLeftX() - 0.5 - moveSpeed, getLeftX() - moveSpeed, getBottomY() + 0.3, getBottomY(), -5);

    /* top */
    SDLGraphics::drawPreciseQuad(0.3, 0.8, 0.3, getLeftX() - 0.5 - moveSpeed, getLeftX() - moveSpeed, getTopY() + 0.3,
                    getTopY(), getLeftX() - 0.5 - moveSpeed + 2, getLeftX() - moveSpeed + 2, getTopY() + 0.3, getTopY(), -5);
}

float Column::getMoveSpeed() { return moveSpeed; }

void Column::setMoveSpeed(float moveSpeed) {
    this->moveSpeed = moveSpeed;
}
