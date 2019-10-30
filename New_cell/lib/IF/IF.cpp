#include "Arduino.h"
#include "IF.hpp"
IF::IF(int RS,int E, int D4, int D5, int D6, int D7,int buzz,int light) : lcd(rs, e, d4, d5, d6, d7)
{
    rs=RS;
    e=E;
    d4=D4;
    d5=D5;
    d6=D6;
    d7=D7;
    _buzz=buzz;
    _light=light;
}
void IF::initialize()
{   
    i_want_to_see=1;
    lcd.begin(16,2);
}
void IF::backlight()
{
  i_want_to_see=!i_want_to_see;
  digitalWrite(_light,i_want_to_see);
}
void IF::display()
{
  
}
