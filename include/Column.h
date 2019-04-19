#ifndef COLUMN_H
#define COLUMN_H

class Column {
    public:
        Column();
        Column(float leftX, float rightX, float topY, float bottomY);
        virtual ~Column();
        float getLeftX();
        float getRightX();
        float getTopY();
        float getBottomY();
        void setVertices(float leftX, float rightX, float topY, float bottomY);
        void drawColumn(float moveSpeed);
    private:
        float leftX;
        float rightX;
        float topY;
        float bottomY;
};

#endif // COLUMN_H
