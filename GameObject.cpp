#include "GameObject.h"
#include <exception>
#include <iostream>
/* Author: William Comer */

/**
 * @brief Construct a new Game Object:: Game Object object
 * 
 */
GameObject::GameObject(){
        //
}

GameObject::GameObject(const char *imageFilePath, int x, int y){
        xpos = x;
        ypos = y;
        setImage(imageFilePath);
}
GameObject::~GameObject(){
    //image.Close();
}

void GameObject::setImage(const char *imageFilePath){
    try
    {
        image.Open(imageFilePath);
        width = image.getCol();
        height = image.getRows();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void GameObject::draw(){
    image.Draw(xpos, ypos);
}

void GameObject::changePos(int dx, int dy){
    xpos += dx;
    ypos += dy;
}
        
bool GameObject::isInside(int x, int y){
    if((x >= xpos && x <= xpos + width -1) && (y >= ypos && y <= ypos + height -1)){
        return true;
    }else{
        return false;
    }
}

bool GameObject::inContact(GameObject* gameObject){
       for(int x = xpos; x <= width; x++){
        for(int y = ypos; y <= height; y++){
            if(gameObject->isInside(x, y)){
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Checks if two gameObjects are colliding
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
    /*
    if(xpos <= gameObject->getXPos() + gameObject->getWidth() &&
    xpos + width > gameObject->getXPos() &&
    ypos < gameObject->getYPos() + gameObject->getHeight() &&
    ypos + height > gameObject->getYPos()){
        return true;
    }else{
        return false;
    }
    */
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

