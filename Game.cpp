#include "Game.h"

/*
This game class holds the methods that allow for drawing the whole game at once.
*/

/** Empty Constructor*/
Game::Game(int dif){

    jump = Button(0, 20, 320, 20, "Jump");
    difficulty = dif;

}


/**
 * @brief Draws the game state
 * 
 */
void Game::draw(){

    map.draw();
    player.draw();
    jump.draw();
    backButton.draw();
}

void Game::play(){

    float x,y;
     while (true)
    {
        draw();

        while (!LCD.Touch(&x, &y))
        {
            player.update();
            Sleep(10);
            LCD.Clear();
            draw();
            
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
        if(backButton.isPressed(x, y)){
            start.menu();
        }
    }

}