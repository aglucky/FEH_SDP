#include "FEHLCD.h"
#include "FEhUtility.h"
#include "mainmenu.h"
#include "player.h"
#include "GameObject.h"
using namespace std;


int main()
{

    // Create nessesary objects
    MainMenu start = MainMenu();
    Button jump = Button( 20,20, 60, 20, "Jump");
    Button left = Button( 100,20, 60, 20, "Left");
    Button right = Button( 180,20, 70, 20, "Right");
    Player test = Player();
    float x, y;
    int difficulty;

    GameObject hello = GameObject("UnicornFEH.pic", 100, 0);
    hello.draw();
    LCD.Update();
    while(true){   
        Sleep(2.0);   
        break;
    
    }
    
    
    // Start the game
    difficulty = start.menu();
    
    while (true)
    {
        jump.draw();
        left.draw();
        right.draw();
        test.draw();

        while (!LCD.Touch(&x, &y))
        {
            test.update();
            Sleep(10);
            LCD.Clear();
            jump.draw();
            left.draw();
            right.draw();
            test.draw();
            test.draw();
            
        }

        if (jump.isPressed(x, y))
        {
            test.jump();
        }
        LCD.Clear();

        if (left.isPressed(x, y))
        {
            test.moveBackward();
        }

        if (right.isPressed(x, y))
        {
            test.moveForward();
        }
    }
    while (true)
    {
        start.menu();
        LCD.Update();
    }
    return 0;
    
    
}
