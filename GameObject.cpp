#include "GameObject.h"


GameObject::GameObject(){

}

GameObject::GameObject(int xPosition, int yPosition, int h, int w){
    xpos = xPosition;
    ypos = yPosition;
    height = h;
    width = w;
}

GameObject::GameObject(int xPosition, int yPosition, int rad){
    xpos = xPosition;
    ypos = yPosition;
    radius = rad;
}

int GameObject::getXPos(){
    return xpos;
}

int GameObject::getYPos(){
    return ypos;
}

int GameObject::getHeight(){
    return height;
}

int GameObject::getWidth(){
    return width;
}

int GameObject::getRadius(){
    return radius;
}
