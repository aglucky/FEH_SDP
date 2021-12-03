#include "FEHLCD.h"
#include "FEhUtility.h"
#include <mainmenu.h>

using namespace std;

class Player
{
private:
    // Player stats and state variables
    int playerScore;
    int playerLives;
    double normalHeight = 200;
    double maxSpeed = 5.5, maxJumpSpeed = -5.0;
    double xSpeed, ySpeed;
    double xAcceleration = 5.2, yAcceleration = 10.2;
    double x, y;
    double time;

public:
    // Constructor and instance methods
    Player();
    // Destructor
    ~Player();
    void moveForward();
    void moveBackward();
    void jump();
    void loseLife();
    void isDead();
    void startTimer();
    void update();
    void draw();
};

// Create a new player
Player::Player()
{
    playerScore = 0;
    playerLives = 3;
    x = 10;
    y = normalHeight;
    time = 0;
}

// Destructor
Player::~Player()
{
    // Nothing to do here
}

//Draw the player as a rectangle
void Player::draw()
{
    LCD.SetFontColor(BLUE);
    LCD.FillRectangle(x, y, 20, 20);
}

//Moves the player forawrd like mario
void Player::moveForward()
{
    xSpeed += xAcceleration;
    if (xSpeed > maxSpeed)
    {
        xSpeed = maxSpeed;
    }
    x += xSpeed;
}

//Moves the player backward like mario
void Player::moveBackward()
{
    xSpeed -= xAcceleration;
    if (xSpeed < -maxSpeed)
    {
        xSpeed = -maxSpeed;
    }
    x += xSpeed;
    
}

//Makes the player jump like mario
void Player::jump()
{
    if (y == normalHeight)
    {
        ySpeed -= yAcceleration;
        if(ySpeed < maxJumpSpeed)
        {
            ySpeed = maxJumpSpeed;
        }
    }
    y+=ySpeed;
}

//Makes the player deccelerate and fall like mario
void Player::update()
{
    //Movement
    if (xSpeed > 0)
    {
        xSpeed -= xAcceleration;
    }
    else if (xSpeed < 0)
    {
        xSpeed += xAcceleration;
    }

    //Jump physics
    if (ySpeed > 0)
    {
        y+=ySpeed;
    }
    else if (ySpeed < 0)
    {
        ySpeed += yAcceleration;
        y+=ySpeed;
    }
    
}



int main()
{

    // Create Main Menu
    MainMenu start = MainMenu();

    Player test = Player();
    
    for(int i = 0; i < 100; i++)
    {
        LCD.Clear(BLACK);
        test.moveForward();
        test.update();
        if(i % 4 == 0)
        {
            test.jump();
        }
        test.draw();
        Sleep(100);
    }

    while (true)
    {
        start.menu();
        LCD.Update();
    }
    return 0;
}
