
/**
 * @brief Handles everything related to the player.
 * 
 */
class Player
{
private:
    // Player stats and state variables
    int playerScore;
    int playerLives;
    double normalHeight = 160;
    double maxSpeed = 5.5, maxJumpSpeed = 14.0;
    double xSpeed, ySpeed;
    double xAcceleration = 5.2, yAcceleration = 2.2;
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