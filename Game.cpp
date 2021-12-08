#include "Game.h"

#define ACTIVE true
#define INACTIVE false
/*
This game class holds the methods that allow for drawing the whole game at once.

NOTE: There is a potential error if a user moves more than 3.Something billion pixels in one direction lol.
*/

/** Empty Constructor*/
Game::Game(int dif)
{
    player = Player(dif, "bryce1FEH.pic", "bryce2FEH.pic", 160, 160);
    difficulty = dif;
    lastActiveEnemyIndex = -1;
}

/**
 * @brief Draws the game state
 * 
 */
void Game::draw()
{

    map.draw();
    player.draw();
    jump.draw();
    backButton.draw();
    for (int i = 0; i < 10; i++)//???HM
    {
        if (enemies[i]->getState())
        {
            enemies[i]->draw();
        }
    }
}

void Game::update(){
    player.update();
    for(int i = 0; i < 10; i++){
        collisionCheck(player, enemies[i]);
        enemies[i]->update(&player);
    }
}

void Game::play()
{

    float x, y;
    while (true)
    {
        draw();

        while (!LCD.Touch(&x, &y))
        {
            update();
            Sleep(10);
            LCD.Clear();
            draw();
            if (lastActiveEnemyIndex == -1)
            {
                spawnEnemy(lastActiveEnemyIndex);
                std::cout << "Spawned an enemy";
            }
        }

        if (jump.isPressed(x, y))
        {
            player.jump();
        }

        else if (x < 120)
        {
            player.moveBackward();
        }

        else if (x > 120)
        {
            player.moveForward();
        }
        LCD.Clear();
        if (backButton.isPressed(x, y))
        {
            player.~Player();
            //Need to prevent additional memory leaks??
            return;
        }
    }
}

void Game::spawnEnemy(int lastActiveEnemy)
{
    if (lastActiveEnemy <= 48)
    {
        enemies[lastActiveEnemy + 1]->setState(true);
        ++lastActiveEnemyIndex;
    }
    else
    {
        std::cout << "Max Number of Enemies Spawned";
    }
}

/**
 * @brief Checks for a collision between a player and an enemy and acts on result
 * 
 * If the player collides with an enemy without jumping on top of them they lose a life.
 * 
 * If the player collides with an enemy by jumping on top of them the enemy "dies"
 * 
 * @param player 
 * @param enemy 
 */
bool Game::collisionCheck(Player player, Enemy *enemy)
{
    //NOTE: Making this too sensitive causes issues because the game does not update/draw itself fast enough.
    int collisionHeight = player.getYPos() + player.getHeight() / 2;
    if (enemy->getState())
    {
        if (GameObject::isColliding(player, *enemy) && collisionHeight < enemy->getYPos())
        {
            enemy->setState(false);
            std::cout << enemy->getState();
            return true;
        }
        else if (GameObject::isColliding(player, *enemy) && collisionHeight > enemy->getYPos())
        {
            player.loseLife();
            //std::cout << player.getLives();
            return true;
        }
    }
    return false;
}

/*

COULD BE OLD CODE THAT WON"T BE USED:

 * @brief Returns the result of a player's collison with a Game Object.
 * 
 * @param p Player Object
 * @param e Enemy Object
 * @return true if the collision doesn't result in the player losing a life
 * @return false if the collsion results in the player losing a life
 
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

*/