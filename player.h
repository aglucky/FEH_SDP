#include "GameObject.h"
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
    double normalHeight = 195;
    double maxSpeed = 5.5, maxJumpSpeed = 25.0;
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
};