#include "GameObject.h"
#include <exception>
#include <iostream>
/* Author: William Comer */

/**
 * @brief Construct a new Game Object:: Game Object object
 * 
 */
GameObject::GameObject(){
        //NEED TO IMPLEMENT A DEFAULT IMAGE
}

GameObject::GameObject(const char *imageFilePath, int x, int y){
        xpos = x;
        ypos = y;
        setImage(imageFilePath);
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

