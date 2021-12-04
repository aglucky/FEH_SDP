#include "GameObject.h"

/* Author: William Comer */

class Platform : public GameObject{
    public:
       Platform();
       Platform(int, int, int, int);

       void draw() override;
       void changePos(int, int) override;
       bool isInside(int, int) override;
       bool inContact(GameObject*) override;
    private:

};