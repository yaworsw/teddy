#include "application.h"

#include "Action.h"

class Twice: public Action {
  public:
    Twice(Action* thing);
    int trigger();
  protected:
    Action* thing;
    bool doneOnce;
};
