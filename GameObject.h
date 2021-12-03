#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\simulator_libraries\FEHLCD.h"
#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\simulator_libraries\FEHUtility.h"

/* Author: William Comer */

class GameObject{
    public:
        GameObject();
        GameObject(int, int, int, int);
        GameObject(int, int, int);
        
        int getXPos();
        int getYPos();
        int getHeight();
        int getWidth();
        int getRadius();
        
        virtual void draw(){};
        virtual void changePos(int, int){};
        virtual bool isInside(int, int){return NULL;};
        virtual bool inContact(GameObject*){return NULL;};
    protected:
        int xpos, ypos, height, width, radius;
};