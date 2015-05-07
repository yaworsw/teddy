#include "application.h"

#include "BlinkEye.h"

BlinkEye::BlinkEye(int pin, int speed, int times) {
  this->pin   = pin;
  this->speed = speed;
  this->times = times;
};

int BlinkEye::trigger() {
  if (this->frame++ < this->times) {
    if (this->frame % 2 == 0) {
      digitalWrite(this->pin, HIGH);
    } else {
      digitalWrite(this->pin, LOW);
    }
    return this->speed;
  } else {
    digitalWrite(this->pin, LOW);
    this->frame = 0;
    return 0;
  }
};
