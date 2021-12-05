#include "mainmenu.h"

/**
 * @brief Construct a new Main Menu:: Main Menu object
 * 
 */
MainMenu::MainMenu() {}

/**
 * @brief Draws the main menu screen
 * 
 */
void MainMenu::drawMain()
{
    LCD.SetBackgroundColor(RED);
    LCD.Clear();
    LCD.WriteAt("Welcome to FEH Adventure", 12, 8);

    playButton.draw();
    statButton.draw();
    ruleButton.draw();
    creditButton.draw();
}

/**
 * @brief Draws the statistic screen
 * 
 */
void MainMenu::drawStats()
{
    LCD.SetBackgroundColor(ORANGE);
    LCD.Clear();
    backButton.draw();
}

/**
 * @brief Draws the rules screen
 * 
 */
void MainMenu::drawRules()
{
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();
    backButton.draw();
}

/**
 * @brief Draws the credits screen
 * 
 */
void MainMenu::drawCredits()
{
    LCD.SetBackgroundColor(YELLOW);
    LCD.Clear();
    backButton.draw();
}

/**
 * @brief Draws the select difficulty screen screen
 * 
 */
void MainMenu::drawPlay()
{
    LCD.SetBackgroundColor(INDIGO);
    LCD.Clear();
    backButton.draw();
    easyButton.draw();
    hardButton.draw();
}

/**
 * @brief Allows user to interact with the main menu
 * 
 * @return Difficulty level of the game 
 */
int MainMenu::menu()
{
    drawMain();

    // Game Loop
    float x, y;
    while (true)
    {
        while (!LCD.Touch(&x, &y))
        {
        }

        // Check for button presses and handles changes
        if (playButton.isPressed(x, y))
        {
            drawPlay();
            while (1)
            {
                Sleep(200);
                while (!LCD.Touch(&x, &y))
                {
                }
                if (backButton.isPressed(x, y))
                {
                    drawMain();
                    Sleep(200);
                    break;
                }
                if(easyButton.isPressed(x, y))
                {
                    return 1;
                }
                if(hardButton.isPressed(x, y))
                {
                    return 2;
                }
                
                
            }
        }
        else if (statButton.isPressed(x, y))
        {
            drawStats();
            while (1)
            {
                Sleep(200);
                while (!LCD.Touch(&x, &y))
                {
                }
                if (backButton.isPressed(x, y))
                {
                    drawMain();
                    Sleep(200);
                    break;
                }
            }
        }
        else if (ruleButton.isPressed(x, y))
        {
            drawRules();
            while (1)
            {
                Sleep(200);
                while (!LCD.Touch(&x, &y))
                {
                }
                if (backButton.isPressed(x, y))
                {
                    drawMain();
                    Sleep(200);
                    break;
                }
            }
        }
        else if (creditButton.isPressed(x, y))
        {
            drawCredits();
            while (1)
            {
                Sleep(200);
                while (!LCD.Touch(&x, &y))
                {
                }
                if (backButton.isPressed(x, y))
                {
                    drawMain();
                    Sleep(200);
                    break;
                }
            }
        }
        // x = 0, y = 0;
    }
}