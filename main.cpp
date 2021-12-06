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