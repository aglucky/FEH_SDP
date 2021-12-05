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
    Button jump = Button(0, 0, 0 ,0, "Jump");
    int difficulty;
};