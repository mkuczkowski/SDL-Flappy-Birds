#ifndef FBGAME_H
#define FBGAME_H

class FBGame {
    public:
        bool isOver;
        float playerPosY;
        FBGame();
        virtual ~FBGame();
        void assignGaps();
        void initialize();
        void restart();
        void render();
        float getJumpHeight();
    private:
        Pipe pipes[100];
        float playerLeftX;
        float playerRightX;
        float playerTopY;
        float playerBottomY;
        float moveSpeed;
        float jumpHeight;
        void drawPlayer();
        void gameOver();
        float getRandomValue(float minValue, float maxValue);
        void checkForCollision(Pipe pipe[]);
        void moveAvailableGameObjects();
};

#endif // FBGAME_H
