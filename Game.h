#include "Background.h"
#include "player.h"
#include "mainmenu.h"
#include "Enemy.h"
#include <random>

/*  Authors: William Comer, Adam Gluck */

/**
 *  @authors William Comer, Adam Gluck
 *  @brief Handles the Game and holds GameObjects.
 * 
 */
class Game
{
public:
    Game(int difficulty, int* s);
    void draw();
    void update();
    void play();

private:
    bool collisionCheck(Player*, Enemy*);

    Player player;
    Button jump = Button(0, 20, 320, 20, "Jump");
    Background map = Background();
    Button quitButton = Button("Quit");

    int difficulty,numberOfStomps, flag, flagh1, flagh2;

    int *stats;

    unsigned int gameStartTime, randTimeInterval;
    
    Enemy a0 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 0, 180);
    Enemy a1 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 0, 180);

    Enemy *enemies[2] = {&a0,&a1};
};