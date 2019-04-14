#ifndef FBGAME_H
#define FBGAME_H

class FBGame
{
    public:
        float playerLeftX;
        float playerRightX;
        float playerTopY;
        float playerBottomY;
        bool isOver;
        float playerPosY;
        float moveSpeed;
        Pipe pipe;
        FBGame();
        virtual ~FBGame();
        void initialize();
        void restart();
        void render();

    protected:

    private:
        void drawPlayer();
        void gameOver();
};

#endif // FBGAME_H
