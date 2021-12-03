#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\simulator_libraries\FEHLCD.h"
#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\simulator_libraries\FEHUtility.h"

class GameObject{
    public:
        GameObject();
        GameObject(float, float, float, float);
        GameObject(float, float, float);
        
        float getXPos();
        float getYPos();
        float getHeight();
        float getWidth();
        float getRadius();
        
        virtual void draw(){};
        virtual void changePos(float, float){};
        virtual void translate(){};
    protected:
        float xpos, ypos, height, width, radius;
};