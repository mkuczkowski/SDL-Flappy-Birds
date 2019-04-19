#include "Column.h"
#include "Pipe.h"
#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

Pipe::Pipe() {}

Pipe::Pipe(float distanceBetween) {
    top.setVertices(4.2, 6.2, 4.2 + distanceBetween, -1.2 + distanceBetween);
    bottom.setVertices(4.2, 6.2, -1.2 - distanceBetween, -5.2 - distanceBetween);
}

Pipe::~Pipe() {}

void Pipe::drawColumns(float moveSpeed) {
    top.drawColumn(moveSpeed);
    bottom.drawColumn(moveSpeed);
}

void Pipe::setupColumns(float distanceBetween, float positionX) {
    top.setVertices(4.2 + positionX, 6.2 + positionX, 7.2 + distanceBetween, -1.2 + distanceBetween);
    bottom.setVertices(4.2 + positionX, 6.2 + positionX, -1.2 - distanceBetween, -9.2 - distanceBetween);
}

void Pipe::setHeight(float distanceToMove) {
    top.setVertices(top.getLeftX(), top.getRightX(), top.getTopY() + distanceToMove, top.getBottomY() + distanceToMove);
    bottom.setVertices(bottom.getLeftX(), bottom.getRightX(), bottom.getTopY() + distanceToMove, bottom.getBottomY() + distanceToMove);
}

Column Pipe::getTop() { return top; }

Column Pipe::getBottom() { return bottom; }
