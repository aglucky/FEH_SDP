#include "GameObject.h"

class Platform : public GameObject{
    public:
       Platform();
       Platform(float, float, float, float);

       void draw() override;
       void changePos(float, float) override;
       void translate() override;
    private:

};