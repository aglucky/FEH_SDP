
/* Author: William Comer */

class GameObject
{
public:
    GameObject();
    GameObject(int, int);

    int getXPos();
    int getYPos();

    // virtual void draw(){};
    // virtual void changePos(int, int){};
    // virtual bool isInside(int, int) { return NULL; };
    // virtual bool inContact(GameObject *) { return NULL; };

protected:
    int xpos, ypos;
};

class GameRect : public GameObject
{
public:
    GameRect(int, int, int, int);
    int getHeight();
    int getWidth();
    void draw();
private:
    int height, width;
};

class GameCircle : public GameObject
{
public:
    GameCircle(int, int, int);
    int getRadius();
    void draw();
private:
    int radius;
};
