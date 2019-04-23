#ifndef FBGAME_H
#define FBGAME_H

class FBGame {
    public:
        bool isOver;
        Player player;
        FBGame();
        virtual ~FBGame();
        void assignGaps();
        void initialize();
        void restart();
        void render();
    private:
        Pipe pipes[100];
        float moveSpeed;
        void gameOver();
        float getRandomValue(float minValue, float maxValue);
        void checkForCollision(Pipe pipe[]);
        void moveAvailableGameObjects();
        void drawBackground();
};

#endif // FBGAME_H
