#include "application.h"

#include <climits>
#include <unistd.h>

#include "Event.h"

Event::Event(std::vector<Action*> actions) {
  this->actions = actions;
  this->size    = actions.size();
};

int Event::trigger() {
  int sleeps [this->size];
  std::fill(sleeps, sleeps + sizeof(sleeps), 0);

  while (true) {
    for (int i = 0; i < this->size; i++) {
      if (sleeps[i] == 0) {
        sleeps[i] = this->actions[i]->trigger();
      }
    }

    int sleep = INT_MAX;
    for (int i = 0; i < this->size; i++) {
      int cur = sleeps[i];
      if (cur >= 0 && sleep > cur) {
        sleep = cur;
      }
    }

    if (sleep != INT_MAX) {
      for (int i = 0; i < this->size; i++) {
        sleeps[i] = sleeps[i] - sleep;
      }
      delay(sleep);
    } else {
      return 0;
    }
  };
};
