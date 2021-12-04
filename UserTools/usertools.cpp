#include "usertools.h"

//Creates a button with a set position and size
Button::Button(float xNew, float yNew, float widthNew, float heightNew, string nm)
{
    x = xNew;
    y = yNew;
    width = widthNew;
    height = heightNew;
    name = nm;
}

//Creates a button with pre-set position and size based on name
Button::Button(string nm)
{
    name = nm;
    width = name.length()*15;
    height = 20.0;
    x = (320 - width);
    y = (240 - height);
}
 
//Shows the button on LCD
void Button::draw()
{
    LCD.DrawRectangle(x, y, width, height);
    LCD.SetFontColor(BLUE);
    LCD.FillRectangle(x, y, width, height);
    LCD.SetFontColor(WHITE);
    LCD.WriteAt(name.c_str(), x+5, y+2);
    LCD.SetFontColor(BLUE);
    
}

//Returns whether a button has been pressed
bool Button::isPressed(float xTouch, float yTouch)
{
    if(xTouch >= x && xTouch <= x+width && yTouch >= y && yTouch <= y+height)
    {
        return true;
    }
    else
    {
        return false;
    }

}