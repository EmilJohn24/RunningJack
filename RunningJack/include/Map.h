#ifndef MAP_H
#define MAP_H
#include "Solid.h"
#include "Player.h"
#include "energyCan.h"
#include "Barrier.h"
#include <conio.h>
#include <windows.h>
class Map
{
    public:
        typedef Solid** Solids;
        double JUMP_STRENGTH = 20;
        double FASTEST_LENGTH = 10;
        double GRAVITY = 2;
        double LONGEST_MOVEMENT = 5;
        int SOLID_LIMIT = 5000;
        Map();
        virtual ~Map();
        void collisionCheck();
        void addSolid(Solid* _solid){
            solidArray[solidCount] = _solid;
            solidCount++;
        };

        void engine();

        void moveEverything();

        void removeSolid(Solid *_solid);

        void jumpAndFall();

    protected:

    private:
        Solid** solidArray;
        Player *player;
        int playerMinimumLevel;
        int solidCount;
        float frameLength = 5;
        int width;
        int height;
        int canGap = 10;
        int barrierGap = 15;
        int frameCount = 0;


};

#endif // MAP_H
