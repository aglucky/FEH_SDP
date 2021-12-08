#include "GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy();
    Enemy(const char *,const char *, int, int);
    void setState(bool);
    bool getState();
    void move();

private:
    bool state;
    int imageDisp = 1;
    double maxSpeed = 5.5, xAcceleration = 5.2, xSpeed; 
    const char *imgFP1, *imgFP2;

    void moveForward();
    void moveBackward();
    void update();
};