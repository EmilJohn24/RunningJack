#ifndef SOLID_H
#define SOLID_H
#include "Graphic.h"

class Solid
{
    public:
        Solid();
        Solid(char *filename, int _id);
        virtual ~Solid();
        int getX(){ return x; };
        int getY(){ return y; };
        int getWidth() { return width; };
        int getHeight() { return height; };
        virtual void collidedAction(Solid *collidedObject) = 0;

        void setX(int _x){
            //sets the x-coord of the solid
            graphicObject->setX(_x);
            this->x = _x;
        };

        void setY(int _y) {
            //sets the y-coord of the solid
            graphicObject->setY(_y);
            this->y = _y;
        };

        void destroy(){
            //destroys the solid and its associated object
            width = 0;
            height = 0;
            graphicObject->destroy();
        }

        void doAnimation(); //performs the animation (if any)
        void move(int dx, int dy){
            //moves the function by a certain displacement
            setX(getX() + dx);
            setY(getY() + dy);
        }
        //setting and getting functions
        void setWidth(int _width) {
            this->width = _width;
        };

        void setHeight(int _height){
            this->height = _height;
        };

        int getID(){
            return id;
        }

        Graphic *getGraphic(){
            return graphicObject;
        };

        void display(){
            //displays the graphic object
            graphicObject->display();
        };

    protected:

    private:
        Graphic *graphicObject;
        int x;
        int y;
        int id;
        int width;
        int height;
};

#endif // SOLID_H
