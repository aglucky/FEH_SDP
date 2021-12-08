#pragma once
#include "GameObject.h"
/* 
    Author: Adam Gluck
    Edited By: William Comer
            --Made it inherit from GameObject in order to be drawn as a GameObject in the Game Class
    Note: the Player class is a child class of the GameObject class
 */

/**
 * @brief Handles everything related to the player.
 * 
 */
class Player : public GameObject
{
private:
    // Player stats and state variables
    int playerScore;
    int playerLives;
    int imageDisp = 1;
    double normalHeight = 160;
    double maxSpeed = 5.5, maxJumpSpeed = 16.0;
    double xSpeed, ySpeed;
    double xAcceleration = 5.2, yAcceleration = 2.2;
    double x, y;
    double time;
    const char *imgFP1, *imgFP2;

public:
    // Constructor and instance methods
    Player();
    Player(int,const char *,const char *, int, int);
    // Destructor
    ~Player();
    void moveForward();
    void moveBackward();
    void jump();
    void loseLife();
    void startTimer();
    void update();
    
    bool isDead();

    int getLives();
};