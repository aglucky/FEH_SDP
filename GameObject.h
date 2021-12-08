#pragma once
#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHImages.h"
#include <string>


/* Author: William Comer

    NOTE: This is the parent class of the Enemy class and the Player class.
 */

class GameObject{
    public:
        GameObject();
        GameObject(const char *, int, int);
        ~GameObject();
        
        int getXPos();
        int getYPos();
        int getHeight();
        int getWidth();
        int getRadius();
        
        void draw();
        static bool isColliding(GameObject, GameObject);
    protected:
        int xpos, ypos, height, width;
        void setImage(const char *);
        FEHIMAGE image;
};