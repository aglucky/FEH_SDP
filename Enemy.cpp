#include "Enemy.h"

#define ACTIVE true
#define INACTIVE false

/* Author: William Comer 
    NOTE: This class is a child class of the class GameObject
*/

/**
 * @brief Construct a new Enemy:: Enemy object Default Constructor
 * 
 */
Enemy::Enemy(){
    state = ACTIVE;
}

/**
 * @brief Construct a new Enemy:: Enemy object with animating images and initial location.
 * 
 * @param imageFilePath1 File path to formated .pic image file frame 1
 * @param imageFilePath2 File path to formated .pic image file frame 2
 * @param x initial x coordinate
 * @param y initial y coordinate
 */
Enemy::Enemy(const char *imageFilePath1, const char *imageFilePath2, int x, int y) : GameObject(imageFilePath1, x, y){
    //Calls the GameObject Parent constructor in its initialization list.
    //sets state to inactive.
    state = INACTIVE;
    imgFP1 = imageFilePath1;
    imgFP2 = imageFilePath2;
}

/**
 * @brief Sets the state to true (ACTIVE) or false (INACTIVE)
 * 
 * @param s desired new state of the object (true or false)
 */
void Enemy::setState(bool s){
    state = s;
}

/**
 * @brief Gets the state of the object
 * 
 * @return true the Object is ACTIVE
 * @return false the Object is INACTIVE
 */
bool Enemy::getState(){
    return state;
}

/**
 * @brief Updates Enemy position variables and allows for an Enemy to follow a player.
 * 
 * @authors Adam Gluck William Comer
 * @param player The player the enemy is going to track
 */
void Enemy::update(Player *player){
    /*
        Author: William Comer
        flag is  used to continue the enemy in the direction it was going before their x position values 
        became the same. 
    */
    bool flag = false;
    //if the enemy is to the right of the player then move left
    if(getXPos() > (player->getXPos())){
        moveBackward();
        flag = true;
    //else if the enemy is to the left of the player then move right
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
        //Every 15 frames switch images.
        if(imageDisp <= 15){
            setImage(imgFP1);
        }else{
            setImage(imgFP2);
        }
    ++imageDisp;
    imageDisp = imageDisp % 30;
//End Author William Comer's Section

//Author: Adam Gluck
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

/**
 * @author Adama Gluck
 * @brief Moves the Enemy in the positive x direction
 * 
 */
void Enemy::moveForward(){
    xSpeed += xAcceleration;
    if (xSpeed > maxSpeed)
    {
        xSpeed = maxSpeed;
    }
}

/**
 *  @author Adam Gluck
 *  @brief Moves the Enemy in the negative x direction
 * 
 */
void Enemy::moveBackward(){
    xSpeed -= xAcceleration;
    if (xSpeed < -maxSpeed)
    {
        xSpeed = -maxSpeed;
    }
}

/**
 * @author William Comer
 * @brief Sets the Enemy's x position.
 *
 * @param x new x coordinate
 */
void Enemy::setXPosition(int x){
    xpos = x;
}