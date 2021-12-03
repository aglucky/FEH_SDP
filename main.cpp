#include "FEHLCD.h"
#include "FEhUtility.h"
#include "mainmenu.h"
#include "Game.h"
#include "Platform.h"
#include <iostream>


using namespace std;

/*
 * Entry point to the application
 */



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
    start.menu();
    }
    return 0;
    */
}








