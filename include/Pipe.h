#ifndef PIPE_H
#define PIPE_H

class Pipe {
    public:
        Column top;
        Column bottom;
        Pipe();
        Pipe(float distanceBetween);
        virtual ~Pipe();
        void drawColumns(float moveSpeed);
        void setupColumns(float distanceBetween);
    protected:

    private:
};

#endif // PIPE_H
