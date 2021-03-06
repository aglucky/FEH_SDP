#include "mainmenu.h"

#define LCD_WIDTH 320
#define LCD_HEIGHT 240

/* Authors: Adam Gluck, Willaim Comer
        Gluck-Created structure and entirety of menu() method.
        Comer-Implemented stats tracking and filled in the different screens
*/

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
    LCD.WriteAt("Welcome to STOMP", 60, 20);

    playButton.draw();
    statButton.draw();
    ruleButton.draw();
    creditButton.draw();
}

/**
 * @brief Draws the statistic screen
 * 
 */
void MainMenu::drawStats(int *stats)
{
    LCD.SetBackgroundColor(ORANGE);
    
    LCD.Clear();
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Statistics",100, 50);
    LCD.WriteAt("From Last Game", 80, 90);
    //Values Returned by last time game was played
    LCD.SetFontColor(BLUE);
    if(*(stats +2) == 1){
    LCD.WriteAt("Dif Lvl: Easy", 10, 120);
    }else if(*(stats + 2) == 2){
    LCD.WriteAt("Dif Lvl: Hard", 10, 120);
    }else{
    LCD.WriteAt("Dif Lvl: ---", 10, 120);
    }
    LCD.WriteAt("STOMPS:", 10, 140);
    LCD.WriteAt(*stats, 95, 140);
    LCD.WriteAt("Time(s):", 10, 160);
    LCD.WriteAt(*(stats + 1), 110, 160);
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
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("RULES", 130, 50);
    LCD.SetFontColor(BLUE);
    LCD.WriteAt("1. Don't Get Touched.", 10, 80);
    LCD.WriteAt("2. STOMP Enemies by", 10, 100);
    LCD.WriteAt("jumping on top of them.", 15, 120);
    LCD.WriteAt("3. Jump with the Button.", 10, 140);
    LCD.WriteAt("4. Move by clicking and", 10, 160);
    LCD.WriteAt("holding on the left or ", 15, 180);
    LCD.WriteAt("right side of the screen.", 15, 200);
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
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Developers", 100, 60);
    LCD.SetFontColor(BLUE);
    LCD.WriteAt("William Comer", 20, 80);
    LCD.WriteAt("Adam Gluck", 20, 110);
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Credits", 100, 140);
    LCD.SetFontColor(BLUE);
    LCD.WriteAt("Simulator Libraries", 20, 160);
    LCD.WriteAt("Developed: FEH Team", 20, 180);
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
int MainMenu::menu(int *stats)
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
            drawStats(stats);
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