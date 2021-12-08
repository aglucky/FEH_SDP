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

Enemy::Enemy(FEHIMAGE * i1, FEHIMAGE *i2, int x, int y) : GameObject(i1, x, y){
    state = INACTIVE;
    imgP1 = i1;
    imgP2 = i2;
}

void Enemy::setState(bool s){
    state = s;
}

bool Enemy::getState(){
    return state;
}

void Enemy::update(Player *player){
    bool flag = false;
    if(getXPos() > (player->getXPos())){
        moveBackward();
        flag = true;
    }else if(getXPos() < (player->getXPos())){
        moveForward();
        flag = false;
    }else{
        if(flag){
            moveForward();
        }else{
            moveBackward();
        }
    }

        if(imageDisp <= 15){
            setImage(imgP1);
        }else{
            setImage(imgP2);
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

void Enemy::moveForward(){
    xSpeed += xAcceleration;
    if (xSpeed > maxSpeed)
    {
        xSpeed = maxSpeed;
    }
}

void Enemy::moveBackward(){
    xSpeed -= xAcceleration;
    if (xSpeed < -maxSpeed)
    {
        xSpeed = -maxSpeed;
    }
}

void Enemy::setXPosition(int x){
    xpos = x;
}