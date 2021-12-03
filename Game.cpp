#include "Game.h"
/* Author: William Comer */

/*
This game class holds the methods that allow for drawing the whole game at once.
*/

/** Empty Constructor*/
Game::Game(){

}

/**
 * @brief Draws the background and then the GameObjects
 * 
 * @param b The background to be drawn
 * @param gameObjects The GameObjects to be drawn
 * @param numObjects How many GameObjects are to be drawn
 */
void Game::draw(Background b, GameObject *gameObjects[], int numObjects){
    drawBackground(b);
    drawObjects(gameObjects, numObjects);
}

/**
 * @brief Draws the background of the game
 * 
 * @param b Background that contains the information necessary to draw the background
 */
void Game::drawBackground(Background b){

}

/**
 * @brief Draws the game objects
 * 
 * @param gameObjects array of pointers to GameObjects
 * @param numObjects the number of Objects in the array, the length
 */
void Game::drawObjects(GameObject *gameObjects[], int numObjects){
    for(int i = 0; i < numObjects; i++){
        gameObjects[i]->draw();
    }
}