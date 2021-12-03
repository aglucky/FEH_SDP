#include "FEHLCD.h"
#include "FEhUtility.h"
#include <mainmenu.h>
#include <math.h>

using namespace std;

class Player
{
private:
    // Player stats and state variables
    int playerScore;
    int playerLives;
    double normalHeight = 180;
    double maxSpeed = 5.5, maxJumpSpeed = 14.0;
    double xSpeed, ySpeed;
    double xAcceleration = 5.2, yAcceleration = -2.2;
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
    LCD.FillRectangle(x, y, 20, 20);
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

int main()
{

    // Create Main Menu
    MainMenu start = MainMenu();
    Button jump = Button(20, 20, 30, 10, "Jump");
    Button left = Button(20, 40, 30, 10, "Left");
    Button right = Button(20, 60, 30, 10, "Right");
    Player test = Player();
    float x, y;

    while (true)
    {
        jump.draw();
        left.draw();
        right.draw();
        test.draw();
        while (!LCD.Touch(&x, &y))
        {
        }

        if (jump.isPressed(x, y))
        {
            test.jump();
        }
        LCD.Clear();

        if (left.isPressed(x, y))
        {
            test.moveBackward();
        }

        if (right.isPressed(x, y))
        {
            test.moveForward();
        }
    }
    while (true)
    {
        start.menu();
        LCD.Update();
    }
    return 0;
}
