#ifndef ANIMATION_H
#define ANIMATION_H
#include "Graphic.h"
class Graphic;
class Animation
{
    public:
        Animation(Graphic **graphics, int _frameCount, double _frameLength): graphicArray(graphics), frameCount(_frameCount), frameLength(_frameLength)  {};
        virtual ~Animation();
        void start(int); //loads the animation how many times the caller desires.
        //since this is not an atomic function, nothing else can be running as it runs.
        void updateGraphicsLocation(int x, int y); //updates the location of every graphic object in the animation
        //void pause();


    protected:

    private:
        int frameCount;
        double frameLength;
        Graphic **graphicArray;
};
#endif // ANIMATION_H
