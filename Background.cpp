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
    ground = GameObject("groundFEH.pic", 0, 20);
}

void Background::draw()
{
    ground.draw();
}