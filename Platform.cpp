#include "Platform.h"
#include <iostream>

Platform::Platform(){

}

Platform::Platform(float xPosition, float yPosition, float h, float w) : GameObject(xPosition, yPosition, h, w){

}

void Platform::draw(){
    LCD.FillRectangle(xpos, ypos, width, height);
}

void Platform::changePos(float dx, float dy){
    LCD.SetFontColor(LCD.Black);
    draw();
    xpos += dx;
    ypos += dy;
    LCD.SetFontColor(LCD.White);
    draw();
}

void Platform::translate(){
    while(true){
        Sleep(1.0);
        break;
    }
}
