#include "Background.h"


/* Author: William Comer */

/**
 * @brief Construct a new Background:: Background object
 *
 * PLACEHOLDER OBJECT
 *
 * NEED TO IMPLEMENT
 *
 */
Background::Background()
{
    ground = GameObject(0,190,50,320);
}

void Background::draw()
{
    ground.draw();
}