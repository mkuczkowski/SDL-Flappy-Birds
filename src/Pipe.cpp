#include "Column.h"
#include "Pipe.h"
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

Pipe::Pipe() {
    movementDirectionVertical = 1;
    movementSpeedVertical = 0.0005;
}

Pipe::Pipe(float distanceBetween) {
    top.setVertices(4.2, 6.2, 4.2 + distanceBetween, -1.2 + distanceBetween);
    bottom.setVertices(4.2, 6.2, -1.2 - distanceBetween, -5.2 - distanceBetween);
    movementDirectionVertical = 1;
    movementSpeedVertical = 0.0005;
}

Pipe::~Pipe() {}

void Pipe::drawColumns(float moveSpeed) {
    top.setMoveSpeed(moveSpeed);
    top.draw();
    bottom.setMoveSpeed(moveSpeed);
    bottom.draw();
}

void Pipe::setupColumns(float positionX) {
    top.setVertices(4.2 + positionX, 6.2 + positionX, 7.2 + verticalDistanceBetween, -1.2 + verticalDistanceBetween);
    bottom.setVertices(4.2 + positionX, 6.2 + positionX, -1.2 - verticalDistanceBetween, -9.2 - verticalDistanceBetween);
}

void Pipe::assignHeightToColumns() {
    top.setVertices(top.getLeftX(), top.getRightX(), top.getTopY() + height, top.getBottomY() + height);
    bottom.setVertices(bottom.getLeftX(), bottom.getRightX(), bottom.getTopY() + height, bottom.getBottomY() + height);
}

Column Pipe::getTop() { return top; }

Column Pipe::getBottom() { return bottom; }

void Pipe::moveVertically() {
    height += movementSpeedVertical * movementDirectionVertical;
    toggleVerticalDirection();
}

void Pipe::toggleVerticalDirection() {
    if(height < -1.5 )
        movementDirectionVertical = 1;
    else if(height > 3.5)
        movementDirectionVertical = -1;
}

float Pipe::getVerticalDistanceBetween() { return verticalDistanceBetween; }

void Pipe::setVerticalDistanceBetween(float verticalDistanceBetween) {
    this->verticalDistanceBetween = verticalDistanceBetween;
}

void Pipe::setHeight(float height) {
    this->height = height;
}
