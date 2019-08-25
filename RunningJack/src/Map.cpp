#include "Map.h"

Map::Map()
{
    //ctor
    solidCount = 0;
    solidArray = (Solid**) malloc(sizeof(Solid*) * SOLID_LIMIT);
    player = new Player();
    height = 100;
    width = 100;
    player->setX(20);
    playerMinimumLevel = height - player->getHeight() - 10;
    player->setY(playerMinimumLevel);
    player->setUpAnimation("playerFrames", FASTEST_LENGTH);

//change later

}

void Map::collisionCheck(){
    //checks for collisions by pairing each solid present in the map
    Solid *first, *second;
    for (int solid1 = 0; solid1 != solidCount; solid1++){
        for (int solid2 = 0; solid2 != solidCount; solid2++){
            if (solid1 == solid2) continue;
            first = solidArray[solid1];
            second = solidArray[solid2];
            gotoxy(0, 0);
            if (first->getX() + first->getWidth() > second->getX() && first->getX() < second->getX() + second->getWidth() &&
                    first->getY() + first->getHeight() > second->getY() && first->getY() < second->getY() + second->getHeight()){
                        first->collidedAction(second);
                }
        }
    }

}
void Map::jumpAndFall(){
    //checks for keyboard input and changes the jump velocity of the player accordingly
    if(kbhit()){
        //printf("Jump sequence...");
        char c = getch();
        if (c == ' '){
            player->addToJumpVelocity((int)JUMP_STRENGTH);
        }
    }
    player->jumpFrame();
    player->addToJumpVelocity(-(int)GRAVITY);
    if (player->getY() == playerMinimumLevel){
        player->zeroOutJumpVelocity();
    }
    if (player->getY() < playerMinimumLevel){
        player->setY(playerMinimumLevel);
        player->zeroOutJumpVelocity();
        //player->

    }
}
void Map::engine(){
    //runs every aspect of the game
    addSolid(player);
    energyCan *tmp;
    Barrier *newBarrier;
    while (1){
        moveEverything();
        jumpAndFall();
        if (frameCount % barrierGap == 0){
            //loads a new barrier in regular intervals
            newBarrier = new Barrier();
            newBarrier->setY(height - newBarrier->getHeight() - 10);
            newBarrier->setX(width); //change
            addSolid(newBarrier);
        }
        else if (frameCount % canGap == 0) {
            //loads a can in regular intervals
            tmp = new energyCan();
            tmp->setY(height - tmp->getHeight() - 10);
            tmp->setX(width);
            addSolid(tmp);
        }


        player->reduceEnergyProportinally(0.999);
        player->doAnimation();
        collisionCheck();
        frameCount += 1;
        Sleep(frameLength * player->getEnergy());
    }

}
void Map::moveEverything(){
    //moves all solids in the map
    double amount = this->LONGEST_MOVEMENT;
    for (int i = 1; i != solidCount; i++){
        solidArray[i]->move(-amount, 0);
        solidArray[i]->display();
    }

}

Map::~Map()
{
    //dtor
}
