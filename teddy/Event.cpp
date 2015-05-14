#include "application.h"

#include "Event.h"

#define MAX_SLEEP 10000000

Event::Event(std::vector<Action*> actions) {
  this->actions = actions;
  this->size    = actions.size();
};

void Event::trigger() {
  int sleeps [this->size];
  std::fill(sleeps, sleeps + sizeof(sleeps), 0);

  while (true) {
    for (int i = 0; i < this->size; i++) {
      if (sleeps[i] == 0) {
        sleeps[i] = this->actions[i]->trigger();
      }
    }

    int sleep = MAX_SLEEP;
    for (int i = 0; i < this->size; i++) {
      int cur = sleeps[i];
      if (cur >= 0 && sleep > cur) {
        sleep = cur;
      }
    }

    if (sleep < MAX_SLEEP) {
      for (int i = 0; i < this->size; i++) {
        if (sleeps[i] >= sleep) {
          sleeps[i] = sleeps[i] - sleep;
        }
      }
      Serial.print("Sleeping for ");
      Serial.print(sleep);
      Serial.println("μs");
      delayMicroseconds(sleep);
    } else {
      return;
    }
  };
};
