#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <stdio.h>
#include "Animation.h"
#include "console.h"
class Animation;
class Graphic
{
    public:
        Graphic(char *filename);
        virtual ~Graphic();
        void display();
        void clearPreviousFrame();
        void createAnimation(char **frameFiles, double frameCount, double frameLength);
        void setUpAnimation(char *infoFile, double frameLength);
        Animation* getAnimator(){return animationContainer;};
        void setX(int _x){
            clearPreviousFrame();
            x = _x;
        };

        void setY(int _y){
            clearPreviousFrame();
            y = _y;
        };

        void setYEmpty(int _y){
            y = _y;
        };

        void setXEmpty(int _x){
            x = _x;
        };


        int getRows(){return rows;};
        int getCols(){return cols;};
        void destroy(){
            this->clearPreviousFrame();
            rows = 0;
            cols = 0;

        };

        void doAnimation();

    protected:

    private:
        static const int FAKE_MAXIMUM = 100;
        Animation* animationContainer;
        int rows;
        int cols;
        int x;
        int y;
        char **text;

};

#endif // GRAPHIC_H
