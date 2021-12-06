#include "Background.h"
#include "player.h"
#include "mainmenu.h"

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
    Button backButton = Button("Back");
    MainMenu start = MainMenu();
    int difficulty;
};