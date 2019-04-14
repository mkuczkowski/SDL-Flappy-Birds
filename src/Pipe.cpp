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

void Pipe::setupColumns(float distanceBetween) {
    top.setVertices(4.2, 6.2, 4.2 + distanceBetween, -1.2 + distanceBetween);
    bottom.setVertices(4.2, 6.2, -1.2 - distanceBetween, -5.2 - distanceBetween);
}
