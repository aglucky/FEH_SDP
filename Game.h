/* Author: William Comer */

#include "Background.h"
#include "player.h"
#include "usertools.h"

class Game
{
public:
    Game(int difficulty);
    void draw();
    void update();
    void play();

private:
    Player player = Player();
    Background map = Background();
    Button jump = Button(20, 20, 60, 20, "Jump");
    int difficulty;
};