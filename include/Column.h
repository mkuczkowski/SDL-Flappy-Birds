#ifndef COLUMN_H
#define COLUMN_H

class Column {
    public:
        Column();
        Column(float leftX, float rightX, float topY, float bottomY);
        virtual ~Column();
        float leftX;
        float rightX;
        float topY;
        float bottomY;
        void setVertices(float leftX, float rightX, float topY, float bottomY);
        void drawColumn(float moveSpeed);
    protected:

    private:
};

#endif // COLUMN_H
