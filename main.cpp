#include "FEHLCD.h"
#include "FEhUtility.h"
<<<<<<< HEAD
#include "mainmenu.h"
#include "Game.h"
#include "Platform.h"
#include <iostream>

=======
#include <mainmenu.h>
#include <player.h>
>>>>>>> main

using namespace std;


int main()
{

<<<<<<< HEAD
int main() {
    Platform a = Platform(0, 0, 20, 20);
    GameObject* test[1] = {&a};
    test[0]->draw();
    while(true){
        while(true){
            test[0]->changePos(-3, 0);
            Sleep(200);
            LCD.Update();
        }
    LCD.Update();
    }
    //Create Main Menu

   /* MainMenu start = MainMenu();
    while(true)
    {
=======
    // Create Main Menu
    MainMenu start = MainMenu();
>>>>>>> main
    start.menu();
    return 0;
    */
}
