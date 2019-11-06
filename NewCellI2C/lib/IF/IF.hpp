#ifndef IF_h
#define IF_h

#include "Arduino.h"
#include <LiquidCrystal_I2C.h>

class IF
{
  public:
    IF(int buzz);
    void backlight();
    void initialize();
    void display(int H, int T);
    void iter();
    boolean i_want_to_see;
    LiquidCrystal_I2C lcd();
  private:
    int _buzz;
    LiquidCrystal_I2C m_lcd;
};

#endif