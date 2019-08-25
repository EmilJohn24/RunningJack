#include "Animation.h"



Animation::~Animation()
{
    //dtor
}

void Animation::start(int repeats){
    for (int i = 0; i != repeats; i++){
        for (int frame = 0; frame != frameCount; frame++){
            Sleep(frameLength);
            if (frame > 0) graphicArray[frame - 1]->clearPreviousFrame();
            graphicArray[frame]->display();
        }
    }
}

void Animation::updateGraphicsLocation(int x, int y){
    for (int i = 0; i != frameCount; i++){
        graphicArray[i]->setXEmpty(x);
        graphicArray[i]->setYEmpty(y);
    }
}
