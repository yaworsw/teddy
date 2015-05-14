#include "application.h"

#include "Action.h"
#include "Song.h"

class PlaySong: public Action {
  public:
    PlaySong(int pin, Song* song);
    int trigger();
  protected:
    int pin;
    Song* song;
    int length;
    int frame = 0;

    int cycleLength;
    int cycle;
    int curCycles;

    bool high;
};
