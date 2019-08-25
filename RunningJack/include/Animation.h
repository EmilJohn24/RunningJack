#ifndef ANIMATION_H
#define ANIMATION_H
#include "Graphic.h"
class Graphic;
class Animation
{
    public:
        Animation(Graphic **graphics, int _frameCount, double _frameLength): graphicArray(graphics), frameCount(_frameCount), frameLength(_frameLength)  {};
        virtual ~Animation();
        void start(int);
        void updateGraphicsLocation(int x, int y);
        //void pause();


    protected:

    private:
        int frameCount;
        double frameLength;
        Graphic **graphicArray;
};
#endif // ANIMATION_H
