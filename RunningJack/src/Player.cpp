#include "Player.h"



Player::~Player()
{
    //dtor
}

void Player::collidedAction(Solid *collidedObject){
    if(collidedObject->getID() == energyCan::ENERGY_CAN_ID){
        reduceEnergyProportinally(1.1);
        collidedObject->destroy();
    }

    else if(collidedObject->getID() == Barrier::BARRIER_ID){
        gameOverSequence();
    }
}

void Player::gameOverSequence(){
    system("cls");
    printf("Game over.");
    exit(0);

}
