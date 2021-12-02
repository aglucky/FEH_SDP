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
    double maxSpeed = 5.5;
    double speed;
    double acceleration = 5.2;
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
    LCD.FillRectangle(x, y, x + 20, y + 20);
}

//Moves the player forawrd like mario
void Player::moveForward()
{
    if (speed < maxSpeed)
    {
        speed += acceleration;
    }
    x += speed;
}

//Moves the player backward like mario
void Player::moveBackward()
{
    if (speed > -maxSpeed)
    {
        speed -= acceleration;
    }
    x += speed;
}

//Makes the player jump like mario
void Player::jump()
{
    if (y == normalHeight)
    {
        y -= 10;
    }
}

//Makes the player deccelerate and fall like mario
void Player::update()
{
    if (speed > 0)
    {
        speed -= acceleration;
    }
    else if (speed < 0)
    {
        speed += acceleration;
    }
    if(y < normalHeight)
    {
        y += 4;
    }
}



int main()
{

    // Create Main Menu
    MainMenu start = MainMenu();

    Player test = Player();
    test.draw();
    Sleep(1.5);
    test.jump();
    LCD.Clear(BLACK);
    test.draw();

    while (true)
    {
        //start.menu();
        LCD.Update();
    }
    return 0;
}
