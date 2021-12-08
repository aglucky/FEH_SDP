#include "Game.h"

#define ACTIVE true
#define INACTIVE false
#define MAX_ENEMIES 3
/*
This game class holds the methods that allow for drawing the whole game at once.

NOTE: There is a potential error if a user moves more than 3.Something billion pixels in one direction lol.
*/

/** Empty Constructor*/
Game::Game(int dif, int *s)
{
    cout <<"well the game was made";
    gameStartTime = TimeNow();
    srand(TimeNowSec());
    player = Player(dif, "bryce1FEH.pic", "bryce2FEH.pic", 160, 160);
    difficulty = dif;
    numberOfStomps = 0;
    randTimeInterval = 8;
    flag = 0;
    stats = s;
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
    quitButton.draw();

    LCD.WriteAt("Lives: ", 0, 100);
    LCD.WriteAt(player.getLives(), 80, 100);
    LCD.Update();
    for (int i = 0; i < MAX_ENEMIES; i++) //???HM
    {
        if (enemies[i]->getState())
        {
            enemies[i]->draw();
        }
    }
}

void Game::update()
{
    ++flag;
    cout << "1";
    player.update();
    cout << "2";
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        collisionCheck(&player, enemies[i]);
        enemies[i]->update(&player);
        if(!(enemies[i]->getState())){
            enemies[i]->setXPosition(0);
            enemies[i]->setState(true);
        }
    }

    //*(stats) = numberOfStomps;
    //*(stats + 1) = TimeNowSec() - gameStartTime;
    //cout << player.getLives();

    //Spawn New Enemies
    /*if(flag % 20 == 0){
        flag %= 20;
        spawnEnemy(0);
    }
    */
    /*
    if (flag % 10 == 0)
    {
        cout << "5";
        flag %= 10;
        switch (difficulty)
        {
        case 1:
            if (TimeNowSec() - timeOfLastSpawn > randTimeInterval)
            {
                randTimeInterval = 1; rand() % 20 + 8
                ;
                timeOfLastSpawn = TimeNowSec();
                spawn();
            }
            break;
        case 2:
            if (TimeNowSec() - timeOfLastSpawn > randTimeInterval)
            {
                randTimeInterval = rand() % 18 + 5;
                timeOfLastSpawn = TimeNowSec() - gameStartTime;
                spawn();
            }
            break;
        }
    }
    */
}

void Game::play()
{
cout << "GAEM PLAY";
    float x, y;
    while (true)
    {
        if (!player.isDead())
        {
            cout << "0";
            draw();
            cout << "-1";
            update();

            while (!LCD.Touch(&x, &y))
            {
                update();
                //Sleep(10);
                LCD.Clear();
                draw();

                /*if(flag == 0){
                    //spawnEnemy(0);
                    enemies[0]->setState(true);
                    std::cout << "Spawned an enemy";
                    flag++;
                }*/

                if (player.isDead())
                {
                    break;
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
        }
        else
        {
            draw();
            LCD.WriteAt("YOU LOSE", 80, 100);
            LCD.Update();
            while (!LCD.Touch(&x, &y))
            {
            }
            //Do something now that the player is dead.
        }
        if (quitButton.isPressed(x, y))
        {
            player.~Player();
            //Need to prevent additional memory leaks??
            return;
        }
    }
}

void Game::spawn()
{
    int rand1 = rand() % 60;
    int rand2 = rand() % 2;
    switch (difficulty)
    {
    case 1:
        spawnEnemy(0);
        break;
    case 2:
        if (rand2 == 1)
        {
            spawnEnemy(rand1);
        }
        else
        {
            spawnEnemy(320 - rand1);
        }
        break;
    default:
        cout << "Not a Valid Difficulty.\n";
    }
}

void Game::spawnEnemy(int xloc)
{
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (!(enemies[i]->getState()))
        {
            enemies[i]->setXPosition(xloc);
            enemies[i]->setState(true);
            return;
        }
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
bool Game::collisionCheck(Player *player, Enemy *enemy)
{
    //NOTE: Making this too sensitive causes issues because the game does not update/draw itself fast enough.
    int collisionHeight = player->getYPos() + player->getHeight() / 2 + player->getHeight() / 4;
    if (enemy->getState())
    {
        if (GameObject::isColliding(*player, *enemy) && collisionHeight < enemy->getYPos())
        {
            enemy->setState(false);
            ++numberOfStomps;
            return true;
        }
        else if (GameObject::isColliding(*player, *enemy) && collisionHeight > enemy->getYPos())
        {
            player->loseLife();
            enemy->setState(false);
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