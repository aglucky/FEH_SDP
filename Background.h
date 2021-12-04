#include "GameObject.h"
/* Author: William Comer */

/* PLACEHOLDER OBJECT NEEDING IMPLEMENTATION*/
class Background{
    public:
        Background();
        void draw();
        void addElement(GameObject*);
    private:
        GameObject ground;
        GameObject elements[50];


};