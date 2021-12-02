#include "FEHLCD.h"
#include "FEhUtility.h"
#include <string>

/*
 * Entry point to the application
 */



class Button
{
    private:
        float x, y, width, height;
        std::string name;
    public:
        Button(float x, float y, float width, float height, std::string name);
        bool isPressed(float, float);
        void draw();
};


class Screen
{
    public:
        Screen(Button prevButton);
        Button prevButton;
        Button backButton= Button(0,0,100,20,"Back");
        void draw();
};

class StartScreen: public Screen
{
    public:
        StartScreen();
        Screen play;
        Screen stat;
        Screen rule;
        Screen credit;
        void draw();
};


        


int main() {

    StartScreen start = StartScreen();
   


    start.draw();
    float x,y;
    while(true)
    {
        while(!LCD.Touch(&x, &y)){}
        if(start.play.prevButton.isPressed(x,y))
        {
            start.play.draw();
        }
        else if(start.stat.prevButton.isPressed(x,y))
        {
            start.stat.draw();
        }
        else if(start.rule.prevButton.isPressed(x,y))
        {
            start.rule.draw();
        }
        else if(start.credit.prevButton.isPressed(x,y))
        {
            start.credit.draw();
        }
       
        

    }
    //Never Closes
    while(true)
    {
        LCD.Update();
    }
 
    return 0;
}

Button::Button(float x, float y, float width, float height, std::string name)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->name = name;
}

void Button::draw()
{
    LCD.DrawRectangle(x, y, width, height);
    LCD.SetFontColor(BLUE);
    LCD.FillRectangle(x, y, width, height);
    LCD.SetFontColor(WHITE);
    LCD.WriteAt(name.c_str(), x+1, y+2);
}

bool Button::isPressed(float x, float y)
{
    if(x > this->x && x < this->x + this->width && y > this->y && y < this->y + this->height)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Screen::Screen(Button prevButton)
{
    this->prevButton = prevButton;
}

StartScreen::StartScreen()
{
    Button playButton = Button(0,100,100,20,"Play");
    this->play = Screen(playButton);

    Button statButton = Button(0,200,100,20,"Stats");
    this->stat = Screen(statButton);

    Button ruleButton = Button(200,100,100,20,"Rules");
    this->rule = Screen(ruleButton);

    Button creditButton = Button(200,200,100,20,"Credits");
    this->credit = Screen(creditButton);
    
}


void StartScreen::draw()
{
    LCD.SetBackgroundColor(RED);
    LCD.Clear();
    LCD.WriteAt("Welcome to FEH Adventure",0,0);

    play.draw();
    stat.draw();
    rule.draw();
    credit.draw();

}

void Screen::draw()
{
    LCD.SetBackgroundColor(BLUE);
    LCD.Clear();

    backButton.draw();
}
