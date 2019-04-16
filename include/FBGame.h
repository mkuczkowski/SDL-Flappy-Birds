#ifndef FBGAME_H
#define FBGAME_H

class FBGame {
    public:
        float playerLeftX;
        float playerRightX;
        float playerTopY;
        float playerBottomY;
        bool isOver;
        float playerPosY;
        float moveSpeed;
        Pipe pipe[4];
        FBGame();
        virtual ~FBGame();
        void assignGaps();
        void initialize();
        void restart();
        void render();
    protected:

    private:
        void drawPlayer();
        void gameOver();
        float getRandomValue(float minValue, float maxValue);
};

#endif // FBGAME_H
