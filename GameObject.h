#pragma once
#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\simulator_libraries\FEHLCD.h"
#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\simulator_libraries\FEHUtility.h"
#include "FEHImages.h"
#include <string>


/* Author: William Comer */

class GameObject{
    public:
        GameObject();
        GameObject(FEHIMAGE *, int, int);
        ~GameObject();
        
        int getXPos();
        int getYPos();
        int getHeight();
        int getWidth();
        int getRadius();
        
        void draw();
        void changePos(int, int);
        bool isInside(int, int);
        bool inContact(GameObject*);
        static bool isColliding(GameObject, GameObject);
    protected:
        int xpos, ypos, height, width;
        void setImage(FEHIMAGE *);
        FEHIMAGE *image;
};