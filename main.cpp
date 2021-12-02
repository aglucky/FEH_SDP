#include "FEHLCD.h"
#include "FEhUtility.h"
#include <mainmenu.h>

using namespace std;

class Player
{
    private:
        int playerScore;
        int playerLives;
        double x, y;
        double time;
        
    public:
        Player();
};



int main() {
   
    //Create Main Menu
    MainMenu start = MainMenu();
    while(true)
    {
    start.menu();
    }
    return 0;
}








