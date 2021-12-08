#include "Background.h"


/* Author: William Comer */

Background::Background(){
    
}

/**
 * @brief Construct a new Background:: Background object
 *
 * PLACEHOLDER OBJECT
 *
 * NEED TO IMPLEMENT
 *
 */
Background::Background(FEHIMAGE *backgroundImage)
{
    ground = GameObject(backgroundImage, 0, 220);
}

void Background::draw()
{
    ground.draw();
}