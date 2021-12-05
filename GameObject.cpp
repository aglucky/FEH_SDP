#include "GameObject.h"
#include "FEHLCD.h"


/**
 * @brief Construct a new GameS:: Game Object object with purely rectangular components
 * 
 * @param xPosition The xPosition of the new GameObject
 * @param yPosition The yPosition of the new GameObject
 * @param h The height of the new GameObject
 * @param w The width of the new GameObject
 */
GameObject:: GameObject(int xPosition, int yPosition, int h, int w){
    x = xPosition;
    y = yPosition;
    height = h;
    width = w;
}




/** 
 * @brief gets the GameObject's radius
 * 
 */
void GameObject::draw(){
    LCD.FillRectangle(x, y, width, height);
}

