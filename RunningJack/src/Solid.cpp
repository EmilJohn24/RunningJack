#include "Solid.h"

Solid::Solid()
{
    //ctor

}

Solid::Solid(char *filename, int _id){
    graphicObject = new Graphic(filename);
    width = graphicObject->getCols();
    height = graphicObject->getRows();
    this->id = _id;
}

void Solid::doAnimation(){
    graphicObject->doAnimation();

}

Solid::~Solid()
{
    //dtor
}
