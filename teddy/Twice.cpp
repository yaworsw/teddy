#include "application.h"

#include "Twice.h"

Twice::Twice(Action* thing) {
  this->thing    = thing;
  this->doneOnce = false;
};

int Twice::trigger() {
  if (!this->doneOnce) {
    int result = this->thing->trigger();
    if (result == -1) {
      this->doneOnce = true;
      return 0;
    }
    return result;
  } else {
    int result = this->thing->trigger();
    if (result == -1) {
      this->doneOnce = false;
    }
    return result;
  }
};
