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
        Button(float, float, float, float, std::string);
        bool isPressed(float, float);
        void draw();
};

class StartScreen
{
    public:
        StartScreen();
        Button playButton;
        Button statButton;
        Button ruleButton;
        Button creditButton;
        void draw();
};

int main() {

    StartScreen start = StartScreen();
    start.draw();
    
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
    LCD.WriteAt(name, x+1, y+2);
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

void StartScreen::StartScreen()
{
    
    this-> playButton = Button(0,100,100,20,"Play");
    this-> statButton= Button(0,200,100,20,"Stats");
    this-> ruleButton= Button(200,100,100,20,"Rules");
    this-> creditButton= Button(200,200,100,20,"Credits");
}

void StartScreen::draw()
{
    playButton.draw();
    statButton.draw();
    ruleButton.draw();
    creditButton.draw();
}
