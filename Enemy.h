#include "GameObject.h"

class Enemy : public GameObject {
    public:
        Enemy();
        Enemy(const char *, int, int);
        void setState(bool);
        bool getState();
    private:
        bool state;
};