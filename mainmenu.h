#include <string>
#include <usertools.h>


class MainMenu
{
    public:
        Button playButton = Button(10,100,100,20,"Play");
        Button statButton = Button(10,200,100,20,"Stats");
        Button ruleButton = Button(210,100,100,20,"Rules");
        Button creditButton = Button(210,200,100,20,"Credits");
        // Button backButton = Button(200,200,100,20,"Back");
        Button backButton = Button("Back");

        MainMenu();
        void drawMain();
        void drawStats();
        void drawRules();
        void drawCredits();
        void drawPlay();
        void menu();
};

MainMenu::MainMenu(){}

void MainMenu::drawMain()
{
    LCD.SetBackgroundColor(RED);
    LCD.Clear();
    LCD.WriteAt("Welcome to FEH Adventure",0,0);

    playButton.draw();
    statButton.draw();
    ruleButton.draw();
    creditButton.draw();    
}

void MainMenu::drawStats()
{
    LCD.SetBackgroundColor(ORANGE);
    LCD.Clear();
    backButton.draw();
}

void MainMenu::drawRules()
{
    LCD.SetBackgroundColor(GREEN);
    LCD.Clear();
    backButton.draw();
}

void MainMenu::drawCredits()
{
    LCD.SetBackgroundColor(YELLOW);
    LCD.Clear();
    backButton.draw();
}

void MainMenu::drawPlay()
{
    LCD.SetBackgroundColor(INDIGO);
    LCD.Clear();
    backButton.draw();
}

void MainMenu::menu()
{
    this->drawMain();
   
    //Game Loop
    float x,y;    
    while(true)
    {
        while(!LCD.Touch(&x,&y)){}
        //Check for button press
        if(this->playButton.isPressed(x,y))
        {
            this->drawPlay();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(this->backButton.isPressed(x,y))
                {
                    this->drawMain();
                    Sleep(200);
                    break;
                }
            }
        }
        else if(this->statButton.isPressed(x,y))
        {
            this->drawStats();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(this->backButton.isPressed(x,y))
                {
                    this->drawMain();
                    Sleep(200);
                    break;
                }
            }
        
        }
        else if(this->ruleButton.isPressed(x,y))
        {
            this->drawRules();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(this->backButton.isPressed(x,y))
                {
                    this->drawMain();
                    Sleep(200);
                    break;
                }
            }
        
        }
        else if(this->creditButton.isPressed(x,y))
        {
            this->drawCredits();
            while(1){
                Sleep(200);
                while(!LCD.Touch(&x,&y)){}
                if(this->backButton.isPressed(x,y))
                {
                    this->drawMain();
                    Sleep(200);
                    break;
                }
            }
        }
        //x = 0, y = 0;
        
    }
}