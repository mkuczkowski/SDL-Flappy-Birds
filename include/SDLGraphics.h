#ifndef SDLGRAPHICS_H
#define SDLGRAPHICS_H

class SDLGraphics {
    public:
        SDLGraphics();
        virtual ~SDLGraphics();
        void initialize();
        void drawQuad(float, float, float, float, float, float, float, float);
        void drawPreciseQuad(   float, float, float, float, float, float, float,
                                float, float, float , float, float  );
        void renderLoop();
};

#endif // SDLGRAPHICS_H
