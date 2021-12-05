#include "usertools.h"

/**
 * @brief Construct a new Button:: Button object
 * 
 * @param xNew x position of the button
 * @param yNew y position of the button
 * @param widthNew width of the button
 * @param heightNew height of the button
 * @param nm The text displayed on the button
 */
Button::Button(float xNew, float yNew, float widthNew, float heightNew, string nm)
{
    x = xNew;
    y = yNew;
    width = widthNew;
    height = heightNew;
    name = nm;
}


/**
 * @brief Construct a new Button:: Button object in the bottom right corner
 * 
 * @param nm The text displayed on the button
 */
Button::Button(string nm)
{
    name = nm;
    width = name.length()*15;
    height = 20.0;
    x = (320 - width);
    y = (240 - height);
}
 

/**
 * @brief Draw the button
 * 
 */
void Button::draw()
{
    LCD.SetFontColor(BLUE);
    LCD.FillRectangle(x, y, width, height);
    LCD.SetFontColor(WHITE);
    LCD.WriteAt(name.c_str(), x+abs(name.length()*12-width)/2, y+2);
    LCD.SetFontColor(BLUE);
    
}

/**
 * @brief Returns whether the button has been pressed
 * 
 * @param xTouch x position of the touch
 * @param yTouch y position of the touch
 * @return true/false on whether button has been pressed
 */
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