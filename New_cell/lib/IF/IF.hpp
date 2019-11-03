#ifndef IF_h
#define IF_h

#include "Arduino.h"
#include <LiquidCrystal.h>

class IF
{
  public:
    IF(int RS,int E, int D4, int D5, int D6, int D7,int light,int buzz);
    void backlight();
    void initialize();
    void display(int H, int T);
    boolean i_want_to_see;
    LiquidCrystal lcd();
  private:
    int rs;
    int e;
    int d4;
    int d5;
    int d6;
    int d7;
    int _light;
    int _buzz;
    LiquidCrystal m_lcd;
};

#endif