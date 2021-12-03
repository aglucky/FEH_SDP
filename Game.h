/* Author: William Comer */
#include "GameObject.h"
#include "Background.h"

class Game{
    public:
        Game();
        void draw(Background, GameObject *[], int);
    private:
        void drawBackground(Background);
        void drawObjects(GameObject *[], int);

};