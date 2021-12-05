#include "Game.h"

/* Author: William Comer */

/*
This game class holds the methods that allow for drawing the whole game at once.
*/

/** Empty Constructor*/
Game::Game(int dif){

    
    difficulty = dif;

}


/**
 * @brief Draws the game state
 * 
 */
void Game::draw(){

    map.draw();
    player.draw();
}

void Game::play(){

    float x,y;
     while (true)
    {
        jump.draw();
        player.draw();

        while (!LCD.Touch(&x, &y))
        {
            player.update();
            Sleep(10);
            LCD.Clear();
            jump.draw();
            player.draw();
            player.draw();
            
        }

        if (jump.isPressed(x, y))
        {
            player.jump();
        }

        else if (x<120)
        {
            player.moveBackward();
        }

        else if (x>120)
        {
            player.moveForward();
        }
                LCD.Clear();

    }

}