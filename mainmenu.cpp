#include "mainmenu.h"

// Initialize the main menu
MainMenu::MainMenu() {}

// Displays the main menu on the LCD
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

// Draws the stat subpage
void MainMenu::drawStats()
{
    LCD.SetBackgroundColor(ORANGE);
    LCD.Clear();
    backButton.draw();
}

// Draws the rules subpage
void MainMenu::drawRules()
{
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();
    backButton.draw();
}

// Draws the credits subpage
void MainMenu::drawCredits()
{
    LCD.SetBackgroundColor(YELLOW);
    LCD.Clear();
    backButton.draw();
}

// Draws the play subpage
void MainMenu::drawPlay()
{
    LCD.SetBackgroundColor(INDIGO);
    LCD.Clear();
    backButton.draw();
    easyButton.draw();
    hardButton.draw();
}

// Allows main menu to be used by player
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