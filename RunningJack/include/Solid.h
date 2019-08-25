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
            graphicObject->setX(_x);
            this->x = _x;
        };

        void setY(int _y) {
            graphicObject->setY(_y);
            this->y = _y;
        };

        void destroy(){
            width = 0;
            height = 0;
            graphicObject->destroy();
        }

        void doAnimation();
        void move(int dx, int dy){
            setX(getX() + dx);
            setY(getY() + dy);
        }

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
