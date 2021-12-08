#include "GameObject.h"

/* Author: William Comer */

/**
 * @brief Handles everything related to the background.
 * 
 * @authors William Comer, Adam Gluck
 */
class Background{
    public:
        Background();
        void draw();
        GameObject ground;
        GameObject background;
};