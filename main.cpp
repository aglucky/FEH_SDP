#include "FEHLCD.h"
#include "FEhUtility.h"
#include "Game.h"
using namespace std;


int main()
{

<<<<<<< Updated upstream
    
    // Create nessesary objects
=======
int main() {
    //Platform a = Platform(0, 0, 100, 100);
    //Platform b = Platform(340, 0, 100, 100);
    //GameObject *test[2] = {&a, &b};
   
   GameObject test1 = GameObject(0, 0, 50, 50);
   GameObject test2 = GameObject(0, 0, 50, 50);
    /*test[0]->draw();
    
    cout << test[1]->getXPos();
    while(true){
        test[0]->changePos(-1, 0);
        cout << test[0]->getXPos();
        Sleep(1.0);
        LCD.Update();
    }
    
    test[1]->draw();
*/
        while(true){
            //test[0]->changePos(-3, 0);
            //test[1]->changePos(3, 0);
            cout << test1.isColliding(test2);
            Sleep(200);
            LCD.Update();
        }
    //Create Main Menu
/*
>>>>>>> Stashed changes
    MainMenu start = MainMenu();
    Player test = Player();
    int difficulty;
    start.menu();

    // Start the game
    while(true)
    {
        // Get the difficulty
        difficulty = start.menu();
        Game game = Game(difficulty);
        game.play();
    }
    return 0;
    
<<<<<<< Updated upstream
}
=======
   */
}








>>>>>>> Stashed changes
