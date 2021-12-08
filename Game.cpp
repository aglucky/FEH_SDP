#include "Game.h"

#define ACTIVE true
#define INACTIVE false
#define MAX_ENEMIES 2
/*

Authors: William Comer Adam Gluck

This game class holds the methods that allow for drawing the whole game at once.

NOTE: There is a potential error if a user moves more than 3.Something billion pixels in one direction lol.
*/

/**
 * @author William Comer
 * @brief Construct a new Game:: Game object
 * 
 * Includes initalizing a player object, setting the difficulty and storing the stats pointer.
 * 
 * @param dif the game difficulty, 1 for easy, 2 for hard
 * @param s integer pointer to where to store the statistics
 */
Game::Game(int dif, int *s)
{
    gameStartTime = TimeNow();
    player = Player(dif, "bryce1FEH.pic", "bryce2FEH.pic", 160, 160);
    difficulty = dif;
    stats = s;
    *(stats + 2) = dif;
    numberOfStomps = 0;
}

/**
 * @authors Adam Gluck, William Comer
 * @brief Draws the game state
 * 
 * Calls all of the GameObjects' draw methods...
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

/**
 *  @author William Comer
 *  @brief This method updates positions for all game objects and updates the current statistics
 * 
 */
void Game::update()
{
    player.update();
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        collisionCheck(&player, enemies[i]);
        enemies[i]->update(&player);
    }

    //Storing statistics
    *(stats) = numberOfStomps;
    *(stats + 1) = TimeNowSec() - gameStartTime;

    if (difficulty == 1) //If the difficulty is set to Easy
    {
        flag++;
        /*
            If the enemy is not active it moves it to position x = 0 and sets it active.
            It does this every 29 times the update method is called.
        */
        if (flag % 30 == 0 && !(enemies[0]->getState())) 
        {
            enemies[0]->setXPosition(0);
            enemies[0]->setState(true);
            flag %= 30;
            flag++;
        }
    }
    if (difficulty == 2)//If the difficulty is set to Hard
    {
        /*
            Similar to the commands for the Easy difficulty, if the enemies are not active it sets them active
            and sets their positions to either the left or right side of the screen depending on which section
            is being excecuted. They execute five executions of the Game::Update() method apart so that the enemies
            don't both reach the middle at exactly the same time.
        */
        flagh1++;
        if (flagh1 % 25 == 0 && !(enemies[0]->getState()))
        {
            enemies[0]->setXPosition(0);
            enemies[0]->setState(true);
            flagh1 %= 30;
            flagh1++;
        }
        flagh2++;
        if (flagh2 % 20 == 0 && !(enemies[1]->getState()))
        {
            enemies[1]->setXPosition(305);
            enemies[1]->setState(true);
            flagh2 %= 20;
            flagh2++;
        }
    }
}

/**
 * @authors Adam Gluck, William Comer
 * @brief Contains the game loop, draws, updates, and gets user input for the game.
 * 
 */
void Game::play()
{
    float x, y;
    while (true)
    {
        if (!player.isDead())
        {
            draw();
            update();

            while (!LCD.Touch(&x, &y))
            {

                update();
                LCD.Clear();
                draw();
                if (player.isDead())
                {
                    x = 0;
                    y = 0;
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
            //Once the player dies print out "You lose"
            LCD.SetFontColor(BLUE);
            LCD.WriteAt("YOU LOSE", 150, 100);
            LCD.WriteAt("Quit To ", 150, 120);
            LCD.WriteAt("Play Again", 150, 140);
            LCD.Update();
            while (!LCD.Touch(&x, &y))
            {
            }
            //wait for the player to quit the game
        }
        if (quitButton.isPressed(x, y))
        {
            player.~Player();
            //Need to prevent additional memory leaks??
            return;
        }
    }
}



/**
 * @author William Comer
 * @brief Checks for a collision between a player and an enemy and acts on result
 * 
 * If the player collides with an enemy without jumping on top of them they lose a life.
 * 
 * If the player collides with an enemy by jumping on top of them the enemy "dies"
 * 
 * @param player player pointer to check for a collision with
 * @param enemy enemy pointer to check for a collision with
 */
bool Game::collisionCheck(Player *player, Enemy *enemy)
{
    //collisionHeight is what is considered "the bottom of the player" for what counts a kill vs losing a life
    //NOTE: Making this too sensitive causes issues because the game does not update/draw itself fast enough.
    int collisionHeight = player->getYPos() + player->getHeight() / 2 + player->getHeight() / 4;

    if (enemy->getState())//If the enemy is active
    {
         //Both cases enemy's state is set to false to prevent one collision subtracting multiple Player lives
        if (GameObject::isColliding(*player, *enemy) && collisionHeight < enemy->getYPos())
        {
            enemy->setState(false);
            ++numberOfStomps;//increment number of stomps
            return true;
        }
        else if (GameObject::isColliding(*player, *enemy) && collisionHeight > enemy->getYPos())
        {
            player->loseLife(); //player loses a life
            enemy->setState(false);
            return true;
        }
    }
    return false;
}
