#ifndef BARRIER_H
#define BARRIER_H

#include "Solid.h"


class Barrier : public Solid
{
    public:
        static const int BARRIER_ID = 3;
        Barrier(): Solid("barrier.txt", BARRIER_ID) {};
        void collidedAction(Solid *collidedObject){
            return;
        };
        virtual ~Barrier();

    protected:

    private:
};

#endif // BARRIER_H
