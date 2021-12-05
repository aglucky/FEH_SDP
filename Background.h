#include "GameObject.h"

/**
 * @brief Handles everything related to the background.
 * 
 */
class Background{
    public:
        Background();
        void draw();
        void addElement(GameObject*);
        GameObject ground = GameObject(0,0,40,40);
        GameObject elements[50];


};