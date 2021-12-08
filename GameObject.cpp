#include "GameObject.h"
#include <exception>
#include <iostream>
/* Author: William Comer */

/**
 * @brief Construct a new Game Object, default constructor
 * 
 */
GameObject::GameObject(){

}

/**
 * @brief Construct a new Game Object with an image and position
 * 
 * @param imageFilePath File path to formated .pic image file
 * @param x initial x position
 * @param y initial y position
 */
GameObject::GameObject(const char *imageFilePath, int x, int y){
        xpos = x;
        ypos = y;
        //Opens an FEHIMAGE Object to allow for drawing and sets the width and height of the GameObject
        setImage(imageFilePath);
}

/**
 * @brief Destroy the Game Object:: Game Object object
 * 
 * Some issues with this if it is attempted to close the image...
 */
GameObject::~GameObject(){
    //image.Close();
}


/**
 * @brief Sets the image to be drawn in the GameObject's draw method
 * 
 * @param imageFilePath File path to formatted. pic image file
 */
void GameObject::setImage(const char *imageFilePath){
    try
    {
        image.Open(imageFilePath);
        //Sets the width and height of the GameObject
        width = image.getCol();
        height = image.getRows();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

/**
 * @brief Draws the GameObject at its current position
 * 
 */
void GameObject::draw(){
    image.Draw(xpos, ypos);
}

/**
 * @brief Static Method that checks if two gameObjects are colliding
 * 
 * Algorithm learned from:
 * @cite label://www.jeffreythompson.org/collision-detection/rect-rect.php
 * 
 * @param gameObject 
 * @return true if colliding
 * @return false if not colliding
 */
bool GameObject::isColliding(GameObject gameObject1, GameObject gameObject2){
    bool a = false, b = false, c = false, d = false;
    if(gameObject2.getXPos() + gameObject2.getWidth() >= gameObject1.getXPos())
    a = true;
    if(gameObject2.getXPos() <= gameObject1.getXPos() + gameObject1.getWidth())
    b = true;
    if(gameObject2.getYPos() + gameObject2.getHeight() >= gameObject1.getYPos())
    c = true;
    if(gameObject2.getYPos() <= gameObject1.getYPos() + gameObject1.getHeight())
    d = true;
    if(a && b && c && d){
        return true;
    }else{
        return false;
    }

}
/**
 * @brief gets the GameObject's X Position
 * 
 * @return int xpos
 */
int GameObject::getXPos(){
    if(xpos < 0){
        return (320 - abs(xpos % 320));
    }else if(xpos > 0){
        return (xpos % 320);
    }else{
    return xpos;
    }
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

