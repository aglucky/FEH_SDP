#include "GameObject.h"


GameObject::GameObject(){

}

GameObject::GameObject(float xPosition, float yPosition, float h, float w){
    xpos = xPosition;
    ypos = yPosition;
    height = h;
    width = w;
}

GameObject::GameObject(float xPosition, float yPosition, float rad){
    xpos = xPosition;
    ypos = yPosition;
    radius = rad;
}

float GameObject::getXPos(){
    return xpos;
}

float GameObject::getYPos(){
    return ypos;
}

float GameObject::getHeight(){
    return height;
}

float GameObject::getWidth(){
    return width;
}

float GameObject::getRadius(){
    return radius;
}
