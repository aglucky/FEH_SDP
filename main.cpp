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
        Button(string name);
        bool isPressed(float, float);
        void draw();
};

class MainMenu
{
    public:
        Button playButton = Button(10,100,100,20,"Play");
        Button statButton = Button(10,200,100,20,"Stats");
        Button ruleButton = Button(210,100,100,20,"Rules");
        Button creditButton = Button(210,200,100,20,"Credits");
        // Button backButton = Button(200,200,100,20,"Back");
        Button backButton = Button("Back");

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
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(start.backButton.isPressed(x,y))
                {
                    start.drawMain();
                    Sleep(200);
                    break;
                }
            }
        }
        else if(start.statButton.isPressed(x,y))
        {
            start.drawStats();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(start.backButton.isPressed(x,y))
                {
                    start.drawMain();
                    Sleep(200);
                    break;
                }
            }
        
        }
        else if(start.ruleButton.isPressed(x,y))
        {
            start.drawRules();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(start.backButton.isPressed(x,y))
                {
                    start.drawMain();
                    Sleep(200);
                    break;
                }
            }
        
        }
        else if(start.creditButton.isPressed(x,y))
        {
            start.drawCredits();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(start.backButton.isPressed(x,y))
                {
                    start.drawMain();
                    Sleep(200);
                    break;
                }
            }
        }
        //x = 0, y = 0;
        
    }
 
    return 0;
}

//Classio
Button::Button(float xNew, float yNew, float widthNew, float heightNew, string nm)
{
    x = xNew;
    y = yNew;
    width = widthNew;
    height = heightNew;
    name = nm;
}

//Button constuctor that puts button in corner using lenght on name as width
Button::Button(string nm)
{
    name = nm;
    width = name.length()*15;
    height = 20.0;
    x = (320 - width);
    y = (240 - height);
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


