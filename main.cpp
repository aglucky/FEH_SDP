#include "FEHLCD.h"
#include "FEhUtility.h"
#include <string>


using namespace std;

/*
 * Entry point to the application
 */


class Button
{
    private:
        float x, y, width, height;
        string name;
    public:
        Button(float x, float y, float width, float height, string name);
        bool isPressed(float, float);
        void draw();
};

class MainMenu
{
    public:
        Button playButton = Button(0,100,100,20,"Play");
        Button statButton = Button(0,200,100,20,"Stats");
        Button ruleButton = Button(200,100,100,20,"Rules");
        Button creditButton =Button(200,200,100,20,"Credits");

        MainMenu();
        void drawMain();
        void drawStats();
        void drawRules();
        void drawCredits();
        void drawPlay();
};




int main() {
   
    //Create Main Menu
    MainMenu start = MainMenu();
    start.drawMain();
   
    //Game Loop
    float x,y;    
    while(true)
    {
        while(!LCD.Touch(&x,&y)){}
        //Check for button press
        if(start.playButton.isPressed(x,y))
        {
            start.drawPlay();
        }
        if(start.statButton.isPressed(x,y))
        {
            start.drawStats();
        }
        if(start.ruleButton.isPressed(x,y))
        {
            start.drawRules();
        }
        if(start.creditButton.isPressed(x,y))
        {
            start.drawCredits();
        }
    }
 
    return 0;
}

Button::Button(float xNew, float yNew, float widthNew, float heightNew, string nm)
{
    x = xNew;
    y = yNew;
    width = 5+nm.length()*20;
    height = heightNew;
    name = nm;
}

void Button::draw()
{
    LCD.DrawRectangle(x, y, width, height);
    LCD.SetFontColor(BLUE);
    LCD.FillRectangle(x, y, width, height);
    LCD.SetFontColor(WHITE);
    LCD.WriteAt(name.c_str(), x+5, y+2);
    LCD.SetFontColor(BLUE);
    
}

bool Button::isPressed(float xTouch, float yTouch)
{
    if(xTouch > x && xTouch < x+width && yTouch > y && yTouch < y+height)
    {
        return true;
    }
    else
    {
        return false;
    }

}


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
    LCD.SetBackgroundColor(BLUE);
    LCD.Clear();
    LCD.WriteAt("Stats",0,0);
}

void MainMenu::drawRules()
{
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();
    LCD.WriteAt("Rules",0,0);
}

void MainMenu::drawCredits()
{
    LCD.SetBackgroundColor(YELLOW);
    LCD.Clear();
    LCD.WriteAt("Credits",0,0);
}

void MainMenu::drawPlay()
{
    LCD.SetBackgroundColor(BLACK);
    LCD.Clear();
    LCD.WriteAt("Play",0,0);
}


