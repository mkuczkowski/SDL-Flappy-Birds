#ifndef QUADRANGLE_H
#define QUADRANGLE_H

class Quadrangle {
    public:
        Quadrangle();
        virtual ~Quadrangle();
        virtual void draw() = 0;
        float getLeftX();
        float getRightX();
        float getTopY();
        float getBottomY();
        void setLeftX(float leftX);
        void setRightX(float rightX);
        void setTopY(float topY);
        void setBottomY(float bottomY);
    private:
        float leftX;
        float rightX;
        float topY;
        float bottomY;
};

#endif // QUADRANGLE_H
