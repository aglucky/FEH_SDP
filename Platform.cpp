#include "Platform.h"
#include <iostream>

Platform::Platform(){

}

Platform::Platform(int xPosition, int yPosition, int h, int w) : GameObject(xPosition, yPosition, h, w){

}

void Platform::draw(){
    LCD.FillRectangle(xpos, ypos, width, height);
}

void Platform::changePos(int dx, int dy){
    LCD.SetFontColor(LCD.Black);
    draw();
    xpos += dx;
    ypos += dy;
    LCD.SetFontColor(LCD.White);
    draw();
}

bool Platform::isInside(int x, int y){
    if((x >= xpos && x <= xpos + width -1) && (y >= ypos && y <= ypos + height -1)){
        return true;
    }else{
        return false;
    }
}

bool Platform::inContact(GameObject *gameObject){
    return NULL;
}
