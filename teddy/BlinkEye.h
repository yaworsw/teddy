#include "application.h"

#include "Action.h"

class BlinkEye: public Action {
  public:
    BlinkEye(int pin, int speed, int times);
    int trigger();
  protected:
    Servo servo;
    int pin;
    int speed;
    int times;
};
