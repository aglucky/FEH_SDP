
#include <math.h>
#include <player.h>
#include "FEHLCD.h"
#include "FEhUtility.h"


// Create a new player
Player::Player()
{
    playerScore = 0;
    playerLives = 3;
    x = 10;
    y = normalHeight - 20;
    time = 0;
}

// Destructor
Player::~Player()
{
    // Nothing to do here
}

// Draw the player as a rectangle
void Player::draw()
{
    LCD.SetFontColor(BLUE);
    LCD.FillRectangle(x, y, 20, 30);
}

// Moves the player forawrd like mario
void Player::moveForward()
{
    xSpeed += xAcceleration;
    if (xSpeed > maxSpeed)
    {
        xSpeed = maxSpeed;
    }
    update();
}

// Moves the player backward like mario
void Player::moveBackward()
{
    xSpeed -= xAcceleration;
    if (xSpeed < -maxSpeed)
    {
        xSpeed = -maxSpeed;
    }
    update();
}

// Makes the player jump like mario
void Player::jump()
{
    if (y == normalHeight)
    {
        ySpeed = maxJumpSpeed;
    }
    update();
}

// Makes the player deccelerate and fall like mario
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

    if (y <= normalHeight)
    {
        ySpeed = 0;
        y = normalHeight;
    }

    if (abs(ySpeed) > maxJumpSpeed)
    {
        ySpeed = maxJumpSpeed;
    }
}
