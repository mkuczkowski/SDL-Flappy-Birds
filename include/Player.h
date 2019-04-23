#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player();
        virtual ~Player();
        void draw();
        void jump();
        float getLeftX();
        float getRightX();
        float getTopY();
        float getBottomY();
        float getPositionY();
        void setPositionY(float position);
        float getFallVelocity();
        void setFallVelocity(float velocity);
    private:
        float positionY;
        float leftX;
        float rightX;
        float topY;
        float bottomY;
        float jumpHeight;
        float fallVelocity;
};

#endif // PLAYER_H
