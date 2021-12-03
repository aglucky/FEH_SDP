#include "GameObject.h"
/* Author: William Comer */

/**
 * @brief Construct a new Game Object:: Game Object object
 * 
 */
GameObject::GameObject(){

}

/**
 * @brief Construct a new Game Object:: Game Object object with purely rectangular components
 * 
 * @param xPosition The xPosition of the new GameObject
 * @param yPosition The yPosition of the new GameObject
 * @param h The height of the new GameObject
 * @param w The width of the new GameObject
 */
GameObject::GameObject(int xPosition, int yPosition, int h, int w){
    xpos = xPosition;
    ypos = yPosition;
    height = h;
    width = w;
    radius = 0;//How do I change this access to private or something similar...?
}

/**
 * @brief Construct a new Game Object:: Game Object object with a radius
 * 
 * @param xPosition The xPosition of the new GameObject
 * @param yPosition The yPosition of the new GameObject
 * @param rad The radius of the new GameObject
 */
GameObject::GameObject(int xPosition, int yPosition, int rad){
    xpos = xPosition;
    ypos = yPosition;
    radius = rad;
    width = 0;//How do I change this access to private or something similar...?
    height = 0;//How do I change this access to private or something similar...?
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
 * @brief gets the GameObject's height
 * 
 * @return int height
 */
int GameObject::getHeight(){
    return height;
}

/**
 * @brief gets the GameObject's width
 * 
 * @return int width
 */
int GameObject::getWidth(){
    return width;
}

/**
 * @brief gets the GameObject's radius
 * 
 * @return int radius
 */
int GameObject::getRadius(){
    return radius;
}
