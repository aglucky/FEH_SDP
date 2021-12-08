#include "Background.h"
#include "player.h"
#include "mainmenu.h"
#include "Enemy.h"

class Game
{
public:
    Game(int difficulty);
    void draw();
    void update();
    void play();

private:
    //bool collisionResult(Player, GameObject*);
    //void collisionCheck(Player, GameObject *[], int);
    void collisionCheck(Player, Enemy);
    void addEnemy();

    Player player;
    Button jump = Button(0, 20, 320, 20, "Jump");
    Background map = Background();
    Button backButton = Button("Back");
    Enemy enemies[50];
    int difficulty;
};