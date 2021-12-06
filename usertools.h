#include "FEHLCD.h"
#include "FEhUtility.h"
#include <string>

using namespace std;

/**
 * @brief Handles everything related to buttons
 * 
 */
class Button
{
    private:
        //Position and Size
        float x, y, width, height;
        string name;
    public:
        //Constructors
        Button(float x, float y, float width, float height, string name);
        Button(string name);
        
        //Instance methods
        bool isPressed(float, float);
        void draw();
};