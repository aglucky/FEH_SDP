#include "FEHLCD.h"
#include "FEhUtility.h"
#include "Game.h"
using namespace std;


int main()
{

    FEHIMAGE p1;
    FEHIMAGE p2;
    FEHIMAGE e1;
    FEHIMAGE e2;
    FEHIMAGE b;
    try
    {
        p1.Open("bryce1FEH.pic");
        p2.Open("bryce2FEH.pic");
        e1.Open("Adam1FEH.pic");
        e2.Open("Adam2FEH.pic");
        b.Open("groundFEH.pic");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    p1.Draw(0,180);
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
        Game game = Game(difficulty, &p1, &p2, &e1, &e2, &b);
        game.play();
    }
    p1.Close();
    p2.Close();
    e1.Close();
    e2.Close();
    b.Close();
    return 0;
    
}
