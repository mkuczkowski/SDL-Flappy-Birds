#ifndef PIPE_H
#define PIPE_H

class Pipe {
    public:
        Column top;
        Column bottom;
        Pipe(float distanceBetween);
        virtual ~Pipe();
        void drawColumns(float moveSpeed);
    protected:

    private:
};

#endif // PIPE_H
