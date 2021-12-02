#include "FEHLCD.h"
#include "FEhUtility.h"
#include <string>

using namespace std;

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