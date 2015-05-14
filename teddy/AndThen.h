#include "application.h"

#include "Action.h"

class AndThen: public Action {
  public:
    AndThen(Action* firstThing, Action* secondThing);
    int trigger();
  protected:
    Action* firstThing;
    Action* secondThing;
    bool firstThingDone;
};
