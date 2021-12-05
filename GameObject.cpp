#include "GameObject.h"


/* Author: William Comer */

/**
 * @brief Create a new game object
 * 
 */
GameObject::GameObject(int x, int y)
{
   xpos = x;
    ypos = y;
}




/**
 * @brief Construct a new GameS:: Game Object object with purely rectangular components
 * 
 * @param xPosition The xPosition of the new GameObject
 * @param yPosition The yPosition of the new GameObject
 * @param h The height of the new GameObject
 * @param w The width of the new GameObject
 */
GameRect:: public GameRect(int xPosition, int yPosition, int h, int w){
    xpos = xPosition;
    ypos = yPosition;
    height = h;
    width = w;
}

/**
 * @brief Construct a new Game Object:: Game Object object with a radius
 * 
 * @param xPosition The xPosition of the new GameObject
 * @param yPosition The yPosition of the new GameObject
 * @param rad The radius of the new GameObject
 */
GameObject:: public GameCircle(int xPosition, int yPosition, int rad){
    xpos = xPosition;
    ypos = yPosition;
    radius = rad;
}

/**
 * @brief gets the GameObject's X Position
 * 
 * @return int xpos
 */
int GameObject::getXPos(){
    return xpos;
}

/**
 * @brief gets the GameObject's Y Position
 * 
 * @return int ypos
 */
int GameObject::getYPos(){
    return ypos;
}

/**
 * @brief Draws the GameObject
 * 
 */
void GameObject::draw(){

LCD.FillRectangle(xpos, ypos, 20, 20);
}

/**
 * @brief gets the GameObject's height
 * 
 * @return int height
 */
int GameRect::getHeight(){
    return height;
}

/**
 * @brief gets the GameObject's width
 * 
 * @return int width
 */
int GameRect::getWidth(){
    return width;
}

/** 
 * @brief gets the GameObject's radius
 * 
 */
void GameRect::draw(){
    LCD.FillRectangle(xpos, ypos, width, height);
}

/**
 * @brief gets the GameObject's radius
 * 
 * @return int radius
 */
int GameCircle::getRadius(){
    return radius;
}

/**
 * @brief Draws the GameCircle
 * 
 */
void GameCircle::draw(){
    LCD.FillCircle(xpos, ypos, radius);
}