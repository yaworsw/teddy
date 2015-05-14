#undef min
#undef max

#include <vector>

#include "Action.h"

class Event {
  public:
    Event(std::vector<Action*>);
    void trigger();
  protected:
    int size;
    std::vector<Action*> actions;
};
