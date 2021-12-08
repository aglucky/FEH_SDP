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
        ~GameObject();
        
        int getXPos();
        int getYPos();
        int getHeight();
        int getWidth();
        int getRadius();
        
<<<<<<< Updated upstream
        void draw();
        void changePos(int, int);
        bool isInside(int, int);
        bool inContact(GameObject*);
=======
        bool isColliding(GameObject);
        virtual void draw(){};
        virtual void changePos(int, int){};
        virtual bool isInside(int, int){return NULL;};
        virtual bool inContact(GameObject*){return NULL;};
>>>>>>> Stashed changes
    protected:
        int xpos, ypos, height, width;
        void setImage(const char *);
        FEHIMAGE image;
};