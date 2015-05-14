#include "Song.h"

Song::Song(int bpm, std::vector<note> notes) {
  this->bpm   = bpm;
  this->notes = notes;
};
