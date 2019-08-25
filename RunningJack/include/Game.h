#ifndef GAME_H
#define GAME_H
#include "Map.h"

class Game
{
    public:
        Game();
        virtual ~Game();


    private:
        Map *gameMap;


};

#endif // GAME_H
