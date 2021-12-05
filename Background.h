#include "GameObject.h"

/**
 * @brief Handles everything related to the background.
 * 
 */
class Background{
    public:
        Background();
        void draw();
        GameObject ground = GameObject(100,100,100,100);
};