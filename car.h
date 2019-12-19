#ifndef CAR_H
#define CAR_H

#include "Arduino.h"

enum class mode{
  btCont,
  selfCont,
  accCont
};

class car{
  private :
    int m1_a, m1_b, m2_a, m2_b;
    mode _mode;
    int _baud;
    char com;
    // int dataf(int num);
    // bool isNum(int data);
  public :
    car(int m1a, int m1b, int m2a, int m2b);
    void _start(mode m = mode::btCont, int b = 9600);
    void btContR();
    void selfContR();
    void accContR();
    void _run();
    void forward();
    void back();
    void stop();
    void left(int dir = 0);
    void right(int dir = 0);
};

#endif
