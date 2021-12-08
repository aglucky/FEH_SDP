#include "GameObject.h"

/**
 * @brief Handles everything related to the background.
 * 
 */
class Background{
    public:
        Background();
        Background(FEHIMAGE *);
        void draw();
        GameObject ground;
};