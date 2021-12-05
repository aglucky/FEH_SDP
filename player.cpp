
#include <math.h>
#include <player.h>
#include "FEHLCD.h"
#include "FEhUtility.h"


/**
 * @brief Construct a new Player:: Player object
 * 
 */
Player::Player()
{
    playerScore = 0;
    playerLives = 3;
    x = 10;
    y = normalHeight - 20;
    time = 0;
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
 * @brief Draws the player on the LCD
 * 
 */
void Player::draw()
{
    LCD.SetFontColor(BLUE);
    LCD.FillRectangle(x, y, 20, 30);
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
    if (y == normalHeight)
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
    // X movement
    x += xSpeed;
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
    y += ySpeed / 2;

    if (y >= normalHeight)
    {
        ySpeed = 0;
        y = normalHeight;
    }

    if (abs(ySpeed) > maxJumpSpeed)
    {
        ySpeed = maxJumpSpeed;
    }
}
