#include "FEHLCD.h"
#include "FEhUtility.h"
#include "Game.h"
using namespace std;


int main()
{

    
    // Create nessesary objects
    MainMenu start = MainMenu();
    Player test = Player();
    int difficulty;
    start.menu();
    /*
    GameObject one = GameObject("basicEnemyFEH.pic", 17, 0);
    GameObject two = GameObject("basicEnemyFEH.pic", 0, 0);
    cout << one.getYPos();
    cout << one.getHeight();
    cout << one.getXPos();
    cout << one.getWidth();
    cout <<"Two:";
     cout << two.getYPos();
    cout << two.getHeight();
    cout << two.getXPos();
    cout << two.getWidth();
    one.draw();
    two.draw();
    cout << GameObject::isColliding(one, two);
    while(true){
        LCD.Update();
        Sleep(2.0);
        break;
    }
    */

    // Start the game
    while(true)
    {
        // Get the difficulty
        difficulty = start.menu();
        Game game = Game(difficulty);
        game.play();
    }
    return 0;
    
}
