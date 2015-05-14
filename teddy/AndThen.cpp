#include "application.h"

#include "AndThen.h"

AndThen::AndThen(Action* firstThing, Action* secondThing) {
  this->firstThing     = firstThing;
  this->secondThing    = secondThing;
  this->firstThingDone = false;
};

int AndThen::trigger() {
  if (!this->firstThingDone) {
    int result = this->firstThing->trigger();
    if (result == -1) {
      this->firstThingDone = true;
    } else {
      return result;
    }
  }
  int secondThingResult = this->secondThing->trigger();
  if (secondThingResult == -1) {
    this->firstThingDone = false;
  }
  return secondThingResult;
};
