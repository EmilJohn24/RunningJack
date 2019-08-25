#ifndef ENERGYCAN_H
#define ENERGYCAN_H

#include "Solid.h"


class energyCan : public Solid
{
    public:
        static const int ENERGY_CAN_ID = 2;
        energyCan(): Solid("energydrink.txt", ENERGY_CAN_ID){};
        virtual void collidedAction(Solid* collidedObject);
        virtual ~energyCan();

    protected:

    private:
};

#endif // ENERGYCAN_H
