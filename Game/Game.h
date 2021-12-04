/* Author: William Comer */
#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\Game\GameObject\GameObject.h"
#include "C:\Users\happy\Documents\FEH\FEH_SDP\FEH_SDP\Game\Background\Background.h"

class Game{
    public:
        Game();
        void draw(Background, GameObject *[], int);
    private:
        void drawBackground(Background);
        void drawObjects(GameObject *[], int);

};