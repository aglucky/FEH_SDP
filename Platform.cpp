#include "Platform.h"
#include <iostream>

/* Author: William Comer */

/**
 * @brief Construct a new Platform:: Platform object
 * 
 */
Platform::Platform() : GameObject(){

}

/**
 * @brief Construct a new Platform:: Platform object
 * 
 * @param xPosition X position of top left corner of platform
 * @param yPosition Y position of top left corner of platform
 * @param h Height of platform
 * @param w Width of platform
 */
Platform::Platform(int xPosition, int yPosition, int h, int w) : GameObject(xPosition, yPosition, h, w){

}

/**
 * @brief Draw this platform on the screen.
 * 
 */
void Platform::draw(){
    LCD.FillRectangle(xpos, ypos, width, height);
    LCD.Update();
}

/**
 * @brief Changes this platforms position and redraws it.
 * 
 * First this method draws over itself to "erase" itself.
 * Then, changes this platforms xpos and ypos values by dx and dy respectively.
 * Redraws this platform in the new location.
 * 
 * @param dx change in x position
 * @param dy change in y position
 */
void Platform::changePos(int dx, int dy){
    LCD.SetFontColor(LCD.Black);
    draw();
    xpos += dx;
    ypos += dy;
    LCD.SetFontColor(LCD.White);
    draw();
}

/**
 * @brief checks if a given set of coordinates are within the boundaries of this platform
 * 
 * @param x x coordinate to check
 * @param y y coordinate to check
 * @return true if the coordinates are within this platform
 * @return false if the coordinates are not within this platform
 */
bool Platform::isInside(int x, int y){
    if((x >= xpos && x <= xpos + width -1) && (y >= ypos && y <= ypos + height -1)){
        return true;
    }else{
        return false;
    }
}

/**
 * @brief Checks if a given gameObject is "colliding"/in contact with this platform.
 * 
 * @param gameObject Pointer to the game object for which the user is checking for a collision with 
 * this platform.
 * @return true if the gameObject is in contact with this platform
 * @return false if the gameObject is not in contact with this platform
 */
bool Platform::inContact(GameObject *gameObject){
    for(int x = xpos; x <= width; x++){
        for(int y = ypos; y <= height; y++){
            if(gameObject->isInside(x, y)){
                return true;
            }
        }
    }
    return false;
}
