#include "application.h"

#include "PlaySong.h"

PlaySong::PlaySong(int pin, Song* song) {
  this->pin         = pin;
  this->song        = song;
  this->frame       = 0;
  this->length      = song->notes.size();

  this->cycleLength = 0;
  this->cycle       = 1;
  this->curCycles   = 0;

  this->high        = true;
};

int PlaySong::trigger() {
  if (this->frame < this->length) {
    if (this->cycle++ > this->curCycles) {
      note cur          = this->song->notes[this->frame++];
      this->cycleLength = 1000000 / cur.freq / 2;
      this->curCycles   = cur.freq * cur.dur / 1000;
      this->cycle       = 0;
      return 100 * 1000; // delay between notes
    }

    if (this->high) {
      digitalWrite(this->pin, HIGH);
    } else {
      digitalWrite(this->pin, LOW);
    }
    this->high = !this->high;

    return this->cycleLength;
  } else {
    return -1;
  }
};
