#ifndef FBGAME_H
#define FBGAME_H

class FBGame: private SDLGraphics {
    public:
        bool isOver;
        Player player;
        FBGame();
        virtual ~FBGame();
        void restart();
        void render();
        SDL_Event* getEvent();
        void quit();
    private:
        SDL_Event event;
        Pipe pipes[100];
        float moveSpeed;
        void gameOver();
        float getRandomValue(float minValue, float maxValue);
        void checkForCollision(Pipe pipe[]);
        void moveAvailableGameObjects();
        void drawBackground();
        void assignGaps();
};

#endif // FBGAME_H
