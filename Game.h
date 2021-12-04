/* Author: William Comer */

#include "Background.h"
#include "player.h"
#include "usertools.h"


class Game{
    public:
        Game(int difficulty);
        void draw();
        void update();
        void play();
    private:
        Player player;
        Background map;
        Button jumpButton;
        int difficulty;

};