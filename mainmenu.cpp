#include "mainmenu.h"

MainMenu::MainMenu(){}

void MainMenu::drawMain()
{
    LCD.SetBackgroundColor(RED);
    LCD.Clear();
    LCD.WriteAt("Welcome to FEH Adventure",0,0);

    playButton.draw();
    statButton.draw();
    ruleButton.draw();
    creditButton.draw();    
}

void MainMenu::drawStats()
{
    LCD.SetBackgroundColor(ORANGE);
    LCD.Clear();
    backButton.draw();
}

void MainMenu::drawRules()
{
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();
    backButton.draw();
}

void MainMenu::drawCredits()
{
    LCD.SetBackgroundColor(YELLOW);
    LCD.Clear();
    backButton.draw();
}

void MainMenu::drawPlay()
{
    LCD.SetBackgroundColor(INDIGO);
    LCD.Clear();
    backButton.draw();
}

void MainMenu::menu()
{
    drawMain();
   
    //Game Loop
    float x,y;    
    while(true)
    {
        while(!LCD.Touch(&x,&y)){}
        //Check for button press
        if(playButton.isPressed(x,y))
        {
            drawPlay();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(backButton.isPressed(x,y))
                {
                    drawMain();
                    Sleep(200);
                    break;
                }
            }
        }
        else if(statButton.isPressed(x,y))
        {
            drawStats();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(backButton.isPressed(x,y))
                {
                    drawMain();
                    Sleep(200);
                    break;
                }
            }
        
        }
        else if(ruleButton.isPressed(x,y))
        {
            drawRules();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(backButton.isPressed(x,y))
                {
                    drawMain();
                    Sleep(200);
                    break;
                }
            }
        
        }
        else if(creditButton.isPressed(x,y))
        {
            drawCredits();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(backButton.isPressed(x,y))
                {
                    drawMain();
                    Sleep(200);
                    break;
                }
            }
        }
        //x = 0, y = 0;
        
    }
}