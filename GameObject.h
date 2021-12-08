#pragma once
#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHImages.h"
#include <string>


/* Author: William Comer */

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
        void changePos(int, int);
        bool isInside(int, int);
        bool inContact(GameObject*);
        static bool isColliding(GameObject, GameObject);
    protected:
        int xpos, ypos, height, width;
        void setImage(const char *);
        FEHIMAGE image;
};