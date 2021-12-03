#include "FEHLCD.h"
#include "FEhUtility.h"
#include "mainmenu.h"
#include "Platform.h"
#include <iostream>


using namespace std;

/*
 * Entry point to the application
 */



int main() {
    Platform a = Platform(0, 0, 100, 100);
    Platform b = Platform(100, 187, 20, 20);
    GameObject *test[2] = {&a, &b};
    cout << test[1]->getYPos();
   
    test[0]->draw();
    /*
    cout << test[1]->getXPos();
    while(true){
        test[0]->changePos(-1, 0);
        cout << test[0]->getXPos();
        Sleep(1.0);
        LCD.Update();
    }
    
    test[1]->draw();

        while(true){
            test[0]->changePos(-3, 0);
            cout << test[0]->getXPos() << "\n"<< test[0]->getYPos();
            test[1]->changePos(3, 0);
            cout << test[0]->inContact(test[1]);
            Sleep(200);
            LCD.Update();
        }
    //Create Main Menu

    MainMenu start = MainMenu();
    while(true)
    {
    start.menu();
    }
    return 0;
    */
   
}








