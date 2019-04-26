#ifndef PIPE_H
#define PIPE_H

class Pipe {
    public:
        Pipe();
        Pipe(float distanceBetween);
        virtual ~Pipe();
        Column getTop();
        Column getBottom();
        float getVerticalDistanceBetween();
        void setVerticalDistanceBetween(float verticalDistanceBetween);
        void setHeight(float height);
        void drawColumns(float moveSpeed);
        void setupColumns(float positionX);
        void assignHeightToColumns();
        void moveVertically();
    private:
        Column top;
        Column bottom;
        void toggleVerticalDirection();
        short movementDirectionVertical;
        float movementSpeedVertical;
        float verticalDistanceBetween;
        float height;
};

#endif // PIPE_H
