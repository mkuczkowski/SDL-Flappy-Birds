#include "Quadrangle.h"

Quadrangle::Quadrangle() {}

Quadrangle::~Quadrangle() {}

float Quadrangle::getLeftX() { return leftX; }

float Quadrangle::getRightX() { return rightX; }

float Quadrangle::getBottomY() { return bottomY; }

float Quadrangle::getTopY() { return topY; }

void Quadrangle::setLeftX(float leftX) {
    this->leftX = leftX;
}

void Quadrangle::setRightX(float rightX) {
    this->rightX = rightX;
}

void Quadrangle::setBottomY(float bottomY) {
    this->bottomY = bottomY;
}

void Quadrangle::setTopY(float topY) {
    this->topY = topY;
}
