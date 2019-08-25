#ifndef PLAYER_H
#define PLAYER_H
#include "Graphic.h"
#include "energyCan.h"
#include "Solid.h"
#include "Barrier.h"
class Player : public Solid
{
    public:
        //using Solid::Solid(char*);
        //player class, most classes here are self-explanatory
        static const int PLAYER_ID = 1;
        Player(): Solid("genericPlayer", PLAYER_ID){
            energy = 1;

        };
        virtual ~Player();
        void setUpAnimation(char *file, double frameLength){
            getGraphic()->setUpAnimation(file, frameLength);
        };

        void collidedAction(Solid *collidedObject);
        double getEnergy(){return energy;};
        void setEnergy(double _energy){ energy = _energy; };
        double reduceEnergy(double _amount) { energy -= _amount; };
        double reduceEnergyProportinally(double _proportion){ energy *= _proportion; };
        void addToJumpVelocity(double _amount){
            jumpVelocity += _amount;
        };
        void jumpFrame(){
            //loads the jumping frame of the object
            this->setY(this->getY() - jumpVelocity);
            this->getGraphic()->getAnimator()->updateGraphicsLocation(this->getX(), this->getY());
        };

        void zeroOutJumpVelocity(){
            jumpVelocity = 0;
        };
        void gameOverSequence();
    protected:

    private:
        double energy;
        double jumpVelocity;



};

#endif // PLAYER_H
