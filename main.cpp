#include "FEHLCD.h"
#include "FEhUtility.h"
#include "Game.h"
using namespace std;

/**
 * @author Adam Gluck
 * @brief Runs the progam
 * 
 */
int main()
{

    // Create nessesary objects
    int stats[3] = {0, 0, 0};
    MainMenu start = MainMenu();
    Player test = Player();
    int difficulty;

    // Start the game
    while (true)
    {
        // Get the difficulty
        difficulty = start.menu(stats);
        //create a new game
        Game game = Game(difficulty, stats);
        //start the game
        game.play();
    }
    return 0;
}
