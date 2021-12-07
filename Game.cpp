#include "Game.h"

/*
This game class holds the methods that allow for drawing the whole game at once.
*/

/** Empty Constructor*/
Game::Game(int dif){

    player = Player(dif, "bryce1FEH.pic", 160, 185);
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
/**
 * @brief Returns the result of a player's collison with a Game Object.
 * 
 * @param p Player Object
 * @param e Enemy Object
 * @return true if the collision doesn't result in the player losing a life
 * @return false if the collsion results in the player losing a life
 */
 bool Game::collisionResult(Player p, GameObject *gameObject){
    if(p.inContact(gameObject) && ((p.getYPos() + p.getHeight()/3) < gameObject->getYPos())){
        return true;
    }else{
        return false;
    }
 }
void Game::collisionCheck(Player p, GameObject *gameObjects[], int numEnemies){
    for(int i = 0; i < numEnemies; i++){
        collisionResult(p, gameObjects[i]);
    }
}