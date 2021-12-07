#pragma once
#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\simulator_libraries\FEHLCD.h"
#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\simulator_libraries\FEHUtility.h"
#include "FEHImages.h"
#include <string>


/* Author: William Comer */

class GameObject{
    public:
        GameObject();
        GameObject(const char *, int, int);
        
        int getXPos();
        int getYPos();
        int getHeight();
        int getWidth();
        int getRadius();
        
        void draw();
        void changePos(int, int);
        bool isInside(int, int);
        bool inContact(GameObject*);
    private:
        int xpos, ypos, height, width;
        FEHIMAGE image;
};