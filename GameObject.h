
/* Author: William Comer */

class GameObject
{
public:
    GameObject(int x, int y, int height, int width);
    void draw();
    // virtual void changePos(int, int){};
    // virtual bool isInside(int, int) { return NULL; };
    // virtual bool inContact(GameObject *) { return NULL; };

private:
    int x,y,width,height;
};

