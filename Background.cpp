#include "Background.h"


/* Author: William Comer */

/**
 * @brief Construct a new Background that has a background and a floor
 * 
 * @authors William Comer, Adam Gluck
 *
 */
Background::Background()
{
    //create ground game object
    ground = GameObject("groundFEH.pic", 0, 220);
    //creat background game object
    background = GameObject("HitchcockFEH.pic", 0, 220);
}

void Background::draw()
{
    //draw the background and then the ground on top of it
    background.draw();
    ground.draw();
}