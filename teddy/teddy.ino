#include <vector>

#include "application.h"

#include "pins.h"

#include "Wave.h"
#include "Event.h"
#include "BlinkEye.h"

Servo leftArm;
Servo rightArm;

int buttonState = 0;

void setup(void) {
  pinMode(SPEAKER_PIN, OUTPUT);

  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);

  leftArm.attach(ARM_PIN_1);
  rightArm.attach(ARM_PIN_2);

  Spark.variable("button", &buttonState, INT);

  Spark.function("setLeftArm", setLeftArm);
  Spark.function("setRightArm", setRightArm);

  Spark.function("celebrate", celebrate);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
}

int setLeftArm(String args) {
  int degs = args.toInt();
  leftArm.write(degs);
  return 0;
}

int setRightArm(String args) {
  int degs = args.toInt();
  rightArm.write(degs);
  return 0;
}

int celebrate(String args) {
  std::vector<Action*> actions;

  Wave leftWave = Wave(leftArm, 200, 0, 90);
  actions.push_back(&leftWave);

  Wave rightWave = Wave(rightArm, 400, 0, 105);
  actions.push_back(&rightWave);

  BlinkEye blinkLeftEye = BlinkEye(LED_PIN_1, 10, 20);
  actions.push_back(&blinkLeftEye);

  BlinkEye blinkRightEye = BlinkEye(LED_PIN_2, 10, 20);
  actions.push_back(&blinkRightEye);

  Event celebrate = Event(actions);
  return celebrate.trigger();
}
