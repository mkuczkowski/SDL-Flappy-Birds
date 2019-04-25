#ifndef PLAYER_H
#define PLAYER_H
#include "SDLGraphics.h"
#include "Quadrangle.h"

class Player: private SDLGraphics, public Quadrangle {
    public:
        Player();
        virtual ~Player();
        void draw();
        void jump();
        float getPositionY();
        void setPositionY(float position);
        float getFallVelocity();
        void setFallVelocity(float velocity);
    private:
        float positionY;
        float jumpHeight;
        float fallVelocity;
};

#endif // PLAYER_H
