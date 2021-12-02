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
    double maxSpeed = .5;
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
    void draw();
};

// Create a new player
Player::Player()
{
    playerScore = 0;
    playerLives = 3;
    x = 10;
    y = 10;
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


int main()
{

    // Create Main Menu
    MainMenu start = MainMenu();
    Player test = Player();
    test.draw();
    Sleep(1.5);
    test.moveForward();
    LCD.Clear(BLACK);
    test.draw();
    while (true)
    {
        //start.menu();
        LCD.Update();
    }
    return 0;
}
