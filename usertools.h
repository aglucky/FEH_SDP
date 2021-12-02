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

