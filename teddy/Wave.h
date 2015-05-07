#include "application.h"

#include "Action.h"

class Wave: public Action {
  public:
    Wave(Servo servo, int speed, int start, int end);
    int trigger();
  protected:
    Servo servo;
    int speed;
    int start;
    int end;
    int frame = 0;
};
