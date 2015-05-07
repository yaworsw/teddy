#include "Wave.h"

Wave::Wave(Servo servo, int speed, int start, int end) {
  this->servo = servo;
  this->speed = speed;
  this->start = start;
  this->end   = end;
};

int Wave::trigger() {
  switch(this->frame++) {
    case 0:
      this->servo.write(this->start);
      return this->speed;
    case 1:
      this->servo.write(this->end);
      return this->speed;
    default:
      this->servo.write(this->start);
      this->frame = 0;
      return -1;
  }
};
