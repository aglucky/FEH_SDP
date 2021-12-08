#include "Background.h"
#include "player.h"
#include "mainmenu.h"
#include "Enemy.h"
#include <random>

class Game
{
public:
    Game(int difficulty, FEHIMAGE *, FEHIMAGE *, FEHIMAGE *, FEHIMAGE *, FEHIMAGE *);
    void draw();
    void update();
    void play();

private:
    //bool collisionResult(Player, GameObject*);
    //void collisionCheck(Player, GameObject *[], int);
    bool collisionCheck(Player*, Enemy*);
    void spawnEnemy(int);
    void spawn();

    Player player;
    Button jump = Button(0, 20, 320, 20, "Jump");
    Background map;
    Button quitButton = Button("Quit");
    int difficulty,numberOfStomps, flag;

    unsigned int gameStartTime, timeOfLastSpawn, randTimeInterval;
    
    Enemy a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
    /*Enemy a10 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a11 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a12 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a13 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a14 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a15 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a16 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a17 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a18 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a19 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a20 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a21 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a22 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a23 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a24 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a25 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a26 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a27 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a28 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a29 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a30 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a31 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a32 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a33 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a34 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a35 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a36 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a37 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a38 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a39 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a40 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a41 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a42 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a43 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a44 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a45 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a46 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a47 = Enemy("Adam1FEH.pic", "AdSam2FEH.pic", 20, 185);
    Enemy a48 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    Enemy a49 = Enemy("Adam1FEH.pic", "Adam2FEH.pic", 20, 185);
    */

    Enemy *enemies[10] = {&a0,&a1,&a2,&a3,&a4,&a5,&a6,&a7,&a8,&a9};/*,&a10,&a11,&a12,&a13,&a14,
    &a15,&a16,&a17,&a18,&a19,&a20,&a21,&a22,&a23,&a24,&a25,&a26,&a27,&a28,&a29,&a30,&a31,
    &a32,&a33,&a34,&a35,&a36,&a37,&a38,&a39,&a40,&a41,&a42,&a43,&a44,&a45,&a46,&a47,&a48,&a49};
    */
};