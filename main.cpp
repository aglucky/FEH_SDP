#include "FEHLCD.h"
#include "FEhUtility.h"
#include "mainmenu.h"


using namespace std;

/*
 * Entry point to the application
 */



int main() {
   
    //Create Main Menu
    MainMenu start = MainMenu();
    while(true)
    {
    start.menu();
    }
    return 0;
}








