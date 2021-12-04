#include "Game.h"
/* Author: William Comer */

/*
This game class holds the methods that allow for drawing the whole game at once.
*/

/** Empty Constructor*/
Game::Game(int dif){

    player = new Player();
    map = new Background();
    jump = Button( 20,20, 60, 20, "Jump");
    difficulty = dif;

}

/** Empty Destructor*/
Game::~Game(){

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
        LCD.Clear();

        else if (x<120)
        {
            player.moveBackward();
        }

        else if (x>120)
        {
            player.moveForward();
        }
    }

}