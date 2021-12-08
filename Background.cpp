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
    ground = GameObject("groundFEH.pic", 0, 220);
    background = GameObject("HitchcockFEH.pic", 0, 220);
}

void Background::draw()
{
    background.draw();
    ground.draw();
}