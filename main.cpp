#include "FEHLCD.h"
#include "FEhUtility.h"
#include "Game.h"
using namespace std;


int main()
{
    GameObject test = GameObject("groundFEH.pic", 0, 220);
    test.draw();
    while(true){
        Sleep(2.0);
        break;
    }
/*
    // Create nessesary objects
    MainMenu start = MainMenu();
    Player test = Player();
    int difficulty;

    // Start the game
    while(true)
    {
        // Get the difficulty
        difficulty = start.menu();
        Game game = Game(difficulty);
        game.play();
    }
    return 0;
    */
}