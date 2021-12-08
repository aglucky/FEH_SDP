#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject
{
public:
    Enemy();
    Enemy(const char *,const char *, int, int);
    void setState(bool);
    bool getState();
    void move();
    void update(Player *);
    void setXPosition(int);

private:
    bool state;
    int imageDisp = 1;
    double maxSpeed = 3, xAcceleration = 5.2, xSpeed; 
    const char *imgFP1, *imgFP2;

    void moveForward();
    void moveBackward();   
};