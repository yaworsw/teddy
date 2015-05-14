#ifndef SONG_H
#define SONG_H

#undef min
#undef max

#include <vector>

#include "note.h"

class Song {
  public:
    Song(int bpm, std::vector<note> notes);
    int bpm;
    std::vector<note> notes;
};

#endif //SONG_H
