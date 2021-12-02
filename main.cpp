#include "FEHLCD.h"
#include "FEhUtility.h"
#include <mainmenu.h>

using namespace std;

class Player
{
    private:
        //Player stats and state variables
        int playerScore;
        int playerLives;
        double maxSpeed = .5;
        double x, y;
        double time;
        
    public:
        //Constructor and instance methods
        Player();
        //Destructor
        ~Player();
        void moveForward();
        void moveBackward();
        void jump();
        void loseLife();
        void isDead();
        void startTimer();
        void draw();
};

//Create a new player
Player::Player()
{
    playerScore = 0;
    playerLives = 3;
    x = 0;
    y = 0;
    time = 0;
}

//Destructor
Player::~Player()
{
    //Nothing to do here
}

//Move the player forward




int main() {
   
    //Create Main Menu
    MainMenu start = MainMenu();
    while(true)
    {
    start.menu();
    }
    return 0;
}








