#include <vector>

#include "application.h"

#include "pins.h"
#include "actions.h"

#include "songs.h"

Servo leftArm;
Servo rightArm;

int buttonState = 0;

void setup(void) {
  Serial.begin(9600);

  pinMode(SPEAKER_PIN, OUTPUT);

  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);

  pinMode(BUTTON_PIN, INPUT);

  leftArm.attach(ARM_PIN_1);
  rightArm.attach(ARM_PIN_2);

  Spark.variable("button", &buttonState, INT);

  Spark.function("set_left_arm", set_left_arm);
  Spark.function("set_right_arm", set_right_arm);

  Spark.function("celebrate", celebrate);
  Spark.function("sing_happy_birthday", sing_happy_birthday);
}

bool firstRun = true;
void loop() {
  if (firstRun) {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, HIGH);
    delay(100);
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    firstRun = false;
  }
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState != 0) {
    delay(1000);
    celebrate("");
  }
}

int set_left_arm(String args) {
  int degs = args.toInt();
  leftArm.write(degs);
  return 0;
}

int set_right_arm(String args) {
  int degs = args.toInt();
  rightArm.write(degs);
  return 0;
}

int celebrate(String args) {
  Serial.println("Celebrate!");

  std::vector<Action*> actions;

  Wave leftWave  = Wave(leftArm, 200, 7, 60);
  Wave leftWave2 = Wave(leftArm, 100, 7, 60);
  Wave leftWave3 = Wave(leftArm, 200, 7, 60);
  Wave leftWave4 = Wave(leftArm, 300, 7, 60);

  Twice secondPhase   = Twice(&leftWave2);
  AndThen thirdPhase  = AndThen(&secondPhase, &leftWave3);
  AndThen fourthPhase = AndThen(&leftWave, &thirdPhase);
  AndThen wholeThing  = AndThen(&fourthPhase, &leftWave4);

  actions.push_back(&wholeThing);

  Wave rightWave  = Wave(rightArm, 300, 120, 7);
  Wave rightWave2 = Wave(rightArm, 600, 120, 7);
  AndThen right   = AndThen(&rightWave, &rightWave2);

  actions.push_back(&right);

  Event celebrate = Event(actions);
  celebrate.trigger();

  return 0;
}

int sing_happy_birthday(String args) {
  Serial.println("Happy Birthday!");

  std::vector<Action*> actions;

  Wave leftWave  = Wave(leftArm, 200, 7, 60);
  Wave leftWave2 = Wave(leftArm, 100, 7, 60);
  Wave leftWave3 = Wave(leftArm, 200, 7, 60);
  Wave leftWave4 = Wave(leftArm, 300, 7, 60);

  Twice secondPhase   = Twice(&leftWave2);
  AndThen thirdPhase  = AndThen(&secondPhase, &leftWave3);
  AndThen fourthPhase = AndThen(&leftWave, &thirdPhase);
  AndThen wholeThing  = AndThen(&fourthPhase, &leftWave4);

  actions.push_back(&wholeThing);

  BlinkEye blinkLeftEye = BlinkEye(LED_PIN_1, 100, 20);
  actions.push_back(&blinkLeftEye);

  BlinkEye blinkRightEye = BlinkEye(LED_PIN_2, 100, 20);
  actions.push_back(&blinkRightEye);

  Song     song     = happy_birthday_song();
  PlaySong playSong = PlaySong(SPEAKER_PIN, &song);
  actions.push_back(&playSong);

  Event celebrate = Event(actions);
  celebrate.trigger();

  return 0;
}
