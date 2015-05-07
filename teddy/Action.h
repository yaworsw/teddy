#ifndef ACTION_H
#define ACTION_H

class Action {
  public:
    virtual int trigger() = 0;
  protected:
    int frame = 0;
};

#endif //ACTION_H
