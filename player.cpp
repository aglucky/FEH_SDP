
#include <math.h>
#include "player.h"
#include "FEHLCD.h"
#include "FEhUtility.h"

#define EASY 1
#define HARD 2

/**
 * @brief Construct a new Player:: Player object
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

Player::Player(int difficulty,FEHIMAGE *img1, FEHIMAGE *img2, int ix, int iy) : GameObject(img1, ix, iy){
    Player();
    imgP1 = img1;
    imgP2 = img2;
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
 * @brief Updates the players position and speed
 * 
 */
void Player::update()
{
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

void Player::loseLife(){
    --playerLives;
}

bool Player::isDead(){
    if(playerLives <= 0){
        return true;
    }else{
        return false;
    }
}

int Player::getLives(){
    return playerLives;
}
