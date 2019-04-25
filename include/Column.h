#ifndef COLUMN_H
#define COLUMN_H
#include "SDLGraphics.h"
#include "Quadrangle.h"

class Column: private SDLGraphics, public Quadrangle {
    public:
        Column();
        Column(float leftX, float rightX, float topY, float bottomY);
        virtual ~Column();
        void setVertices(float leftX, float rightX, float topY, float bottomY);
        void draw();
        float getMoveSpeed();
        void setMoveSpeed(float moveSpeed);
    private:
        float moveSpeed;
};

#endif // COLUMN_H
