
#include <math.h>
#include "player.h"
#include "FEHLCD.h"
#include "FEhUtility.h"

#define EASY 1
#define HARD 2

/*
    Author: Adam Gluck
    Edited: William Comer
*/

/**
 * @author Adam Gluck
 * @brief Construct a new Player:: Player object Default constructor
 * 
 */
Player::Player()
{
    playerScore = 0;
    playerLives = 3;
    xpos = 10;
    ypos = normalHeight - 20;
    time = 0;
}

/**
 * @author William Comer
 * @brief Construct a new Player:: Player object that is a GameObject
 * 
 * @param difficulty 
 * @param imageFilePath1 
 * @param imageFilePath2 
 * @param ix 
 * @param iy 
 */
Player::Player(int difficulty,const char *imageFilePath1, const char *imageFilePath2, int ix, int iy) : GameObject(imageFilePath1, ix, iy){
    Player();//Calls default constructor
    imgFP1 = imageFilePath1;
    imgFP2 = imageFilePath2;
    switch (difficulty){
        case EASY:
            playerLives = 5;
            break;
        case HARD:
            playerLives = 3;
            break;
        default:
            playerLives = 0;
    }
}
/**
 * @brief Destroy the Player:: Player object
 * 
 */
Player::~Player()
{
    // Nothing to do here
}

/**
 * @author Adam Gluck
 * @brief Moves the player right on the LCD
 * 
 */
void Player::moveForward()
{
    xSpeed += xAcceleration;
    if (xSpeed > maxSpeed)
    {
        xSpeed = maxSpeed;
    }
    update();
}

/**
 * @author Adam Gluck
 * @brief Moves the player left on the LCD
 * 
 */
void Player::moveBackward()
{
    xSpeed -= xAcceleration;
    if (xSpeed < -maxSpeed)
    {
        xSpeed = -maxSpeed;
    }
    update();
}

/**
 * @author Adam Gluck
 * @brief Makes the player jump
 * 
 */
void Player::jump()
{
    if (ypos == normalHeight)
    {
        ySpeed = -maxJumpSpeed;
    }
    update();
}

/**
 * @authors Adam Gluck, William Comer
 * @brief Updates the players position and speed
 * 
 */
void Player::update()
{
    //Author: William Comer
    //Fliping the images to be drawn creating animation effect
        if(imageDisp <= 15){
            setImage(imgFP1);
        }else{
            setImage(imgFP2);
        }
    ++imageDisp;
    imageDisp = imageDisp % 30;
    //End Comer

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

    // Y movement
    if (abs(ySpeed) > 0)
    {
        ySpeed += yAcceleration / 2;
    }
    ypos += ySpeed / 2;

    if (ypos >= normalHeight)
    {
        ySpeed = 0;
        ypos = normalHeight;
    }

    if (abs(ySpeed) > maxJumpSpeed)
    {
        ySpeed = maxJumpSpeed;
    }
}

/**
 * @author William Comer
 * @brief decriments the player's lives by 1
 * 
 */
void Player::loseLife(){
    --playerLives;
}

/**
 * @author William Comer
 * @brief Returns if the player is out of lives
 * 
 * @return true if lives <= 0
 * @return false if lives > 0
 */
bool Player::isDead(){
    if(playerLives <= 0){
        return true;
    }else{
        return false;
    }
}

/**
 * @author William Comer
 * @brief Returns how many lives the Player has
 * 
 * @return int Number of Lives
 */
int Player::getLives(){
    return playerLives;
}
