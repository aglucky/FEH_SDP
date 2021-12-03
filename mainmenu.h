#include <string>
#include <usertools.h>

//Class that handles everything related to the main menu
class MainMenu
{
    public:
        //All buttons for main menu and it's sub pages
        Button playButton = Button(10,100,100,20,"Play");
        Button statButton = Button(10,200,100,20,"Stats");
        Button ruleButton = Button(210,100,100,20,"Rules");
        Button creditButton = Button(210,200,100,20,"Credits");
        // Button backButton = Button(200,200,100,20,"Back");
        Button backButton = Button("Back");
        
        //Constructor and instance methods
        MainMenu();
        void drawMain();
        void drawStats();
        void drawRules();
        void drawCredits();
        void drawPlay();
        void menu();
};