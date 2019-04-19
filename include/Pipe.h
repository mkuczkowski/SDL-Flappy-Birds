#ifndef PIPE_H
#define PIPE_H

class Pipe {
    public:
        Pipe();
        Pipe(float distanceBetween);
        virtual ~Pipe();
        Column getTop();
        Column getBottom();
        void drawColumns(float moveSpeed);
        void setupColumns(float distanceBetween, float positionX);
        void setHeight(float distanceToMove);
    private:
        Column top;
        Column bottom;
};

#endif // PIPE_H
