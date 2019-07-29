#ifndef FBGAME_H
#define FBGAME_H

class FBGame: private SDLGraphics {
    public:
        FBGame();
        virtual ~FBGame();
        void start();
    private:
        SDL_Event event;
        Player player;
        bool isOver;
        Pipe pipes[100];
        float moveSpeed;
        float distanceBetweenPipes;
        void gameOver();
        float getRandomValue(float minValue, float maxValue);
        void checkForCollisions();
        void moveAvailableGameObjects();
        void drawBackground();
        void assignGaps();
        void quit();
        void render();
        void restart();
};

#endif // FBGAME_H
