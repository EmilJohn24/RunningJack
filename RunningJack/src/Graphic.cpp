#include "Graphic.h"



void Graphic::clearPreviousFrame(){
    gotoxy(x, y);
    for (int row = 0; row != rows; row++){
        gotoxy(x, y + row);
        for (int col = 0; col != cols; col++){
            printf("%c", ' ');
        }
    }
}
void Graphic::setUpAnimation(char *infoFile, double frameLength){
    FILE *playerFrameInfo = fopen(infoFile, "r");
    if (playerFrameInfo == NULL){
        printf("Error opening file.");
    }
    char **filenames = (char**) malloc(sizeof(char*) * 30);
    int i = 0;
    while(!feof(playerFrameInfo)){
        filenames[i] = (char*) malloc(sizeof(char) * 100);
        fscanf(playerFrameInfo, "%s", filenames[i]);
       // printf("Opened %s\n", filenames[i]);
        i++;
    }
    createAnimation(filenames, i, frameLength);


}
void Graphic::createAnimation(char **frameFiles, double frameCount, double frameLength){
    Graphic **frames = (Graphic**) malloc(sizeof(Graphic*) * frameCount);
    for (int i = 0; i != frameCount; i++){
        frames[i] = new Graphic(frameFiles[i]);
        frames[i]->setX(x);
        frames[i]->setY(y);
    }
    animationContainer = new Animation(frames, frameCount, frameLength);
}

void Graphic::display(){
    gotoxy(x, y);
            //normal display
    for (int row = 0; row != rows; row++){
        gotoxy(x, y + row);
        printf("%s", this->text[row]);
    }


}

Graphic::Graphic(char* filename){
    animationContainer = NULL;
    FILE *graphicFile = fopen(filename, "r");
    text = (char**) malloc(FAKE_MAXIMUM * sizeof(char*));
    rows = 0;
    cols = 0;
    x = 0;
    y = 0;
    //load graphic container
    for (int i = 0; i != FAKE_MAXIMUM; i++){
        text[i] = (char*) malloc(FAKE_MAXIMUM * sizeof(char));

    }

    int tempCols = 0;
    int c; //temporary character storage
    while (!feof(graphicFile)){
        tempCols = 0;
        while ((c = fgetc(graphicFile)) != '\n'){
            if (feof(graphicFile)) break;
            text[rows][tempCols] = c;
            tempCols++;
        }
        if (tempCols > cols) cols = tempCols;
        text[rows][tempCols] = 0;
        rows++;
    }

    //load graphics into array



}

void Graphic::doAnimation(){
    if (animationContainer != NULL){
        animationContainer->start(1);
    }
    else{
        printf("Random animation error.");
    }
}
Graphic::~Graphic()
{
    //dtor
}
