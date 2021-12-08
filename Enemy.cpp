#include "Enemy.h"

#define ACTIVE true
#define INACTIVE false

/* Author: William Comer */

/**
 * @brief Construct a new Enemy:: Enemy object
 * 
 */
Enemy::Enemy(){
    state = ACTIVE;
}

Enemy::Enemy(const char *imageFilePath1, const char *imageFilePath2, int x, int y) : GameObject(imageFilePath1, x, y){
    state = INACTIVE;
    imgFP1 = imageFilePath1;
    imgFP2 = imageFilePath2;
}

void Enemy::setState(bool s){
    state = s;
}

bool Enemy::getState(){
    return state;
}

void Enemy::update(){

        if(imageDisp <= 15){
            setImage(imgFP1);
        }else{
            setImage(imgFP2);
        }
    ++imageDisp;
    imageDisp = imageDisp % 30;
    // X movement
    xpos += xSpeed;
    if (xSpeed > 0)
    {
        xSpeed -= xAcceleration;
        if (xSpeed < 0)
        {
            xSpeed = 0;
        }
    }
    else if (xSpeed < 0)
    {
        xSpeed += xAcceleration;
        if (xSpeed > 0)
        {
            xSpeed = 0;
        }
    }
}