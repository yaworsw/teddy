#ifndef SONGS_H
#define SONGS_H

#undef min
#undef max

#include <vector>

#include "Song.h"

Song mario_theme_song() {
  std::vector<note> notes;
  notes.push_back({ NOTE_E7, FULL_NOTE });
  notes.push_back({ NOTE_E7, FULL_NOTE });
  notes.push_back({       0, FULL_NOTE }); // skip
  notes.push_back({ NOTE_E7, FULL_NOTE });
  notes.push_back({       0, FULL_NOTE }); // skip
  notes.push_back({ NOTE_C7, FULL_NOTE });
  notes.push_back({ NOTE_E7, FULL_NOTE });
  notes.push_back({       0, FULL_NOTE }); // skip
  return Song(120, notes);
};

Song happy_birthday_song() {
  std::vector<note> notes;

  notes.push_back({ NOTE_C4, EIGHTH_NOTE });
  notes.push_back({ NOTE_C4, EIGHTH_NOTE });
  notes.push_back({ NOTE_D4, QUARTER_NOTE });
  notes.push_back({ NOTE_C4, QUARTER_NOTE });
  notes.push_back({ NOTE_F4, QUARTER_NOTE });
  notes.push_back({ NOTE_E4, HALF_NOTE });
  notes.push_back({ NOTE_C4, EIGHTH_NOTE });
  notes.push_back({ NOTE_C4, EIGHTH_NOTE });
  notes.push_back({ NOTE_D4, QUARTER_NOTE });
  notes.push_back({ NOTE_C4, QUARTER_NOTE });
  notes.push_back({ NOTE_G4, QUARTER_NOTE });
  notes.push_back({ NOTE_F4, HALF_NOTE });
  notes.push_back({ NOTE_C4, EIGHTH_NOTE });
  notes.push_back({ NOTE_C4, EIGHTH_NOTE });
  notes.push_back({ NOTE_C5, QUARTER_NOTE });
  notes.push_back({ NOTE_A5, QUARTER_NOTE });
  notes.push_back({ NOTE_F4, QUARTER_NOTE });
  notes.push_back({ NOTE_E4, QUARTER_NOTE });
  notes.push_back({ NOTE_D4, HALF_NOTE });
  notes.push_back({ NOTE_AS5, EIGHTH_NOTE });
  notes.push_back({ NOTE_AS5, EIGHTH_NOTE });
  notes.push_back({ NOTE_A5, QUARTER_NOTE });
  notes.push_back({ NOTE_F4, QUARTER_NOTE });
  notes.push_back({ NOTE_G4, QUARTER_NOTE });
  notes.push_back({ NOTE_F4, HALF_NOTE });

  return Song(70, notes);
};

#endif //SONGS_H
