#include "Arduino.h"
#include "IF.hpp"
IF::IF(int RS,int E, int D4, int D5, int D6, int D7,int light,int buzz) : m_lcd(RS, E, D4, D5, D6, D7)
{
    rs=RS;
    e=E;
    d4=D4;
    d5=D5;
    d6=D6;
    d7=D7;
    _light=light;
    _buzz=buzz;
}
void IF::initialize()
{   
    i_want_to_see=1;
    m_lcd.begin(16,2);
    pinMode(_light,OUTPUT);
    pinMode(_buzz,OUTPUT);
    digitalWrite(_light,i_want_to_see);
    digitalWrite(_buzz,LOW);
}
void IF::backlight()
{
  i_want_to_see=!i_want_to_see;
  digitalWrite(_light,i_want_to_see);
  if(i_want_to_see)
  {
    m_lcd.display();
  }
  else
  {
    m_lcd.noDisplay();
  }
}
void IF::display(int H, int T)
{
     m_lcd.setCursor(0,0);
     m_lcd.print(H);
     m_lcd.setCursor(2,0);
     m_lcd.print("%");
     m_lcd.setCursor(0,1);
     m_lcd.print(T);
     m_lcd.setCursor(2,1);
     m_lcd.print("*C");
     if((H<60)||(T>30))
{
digitalWrite(_buzz,HIGH);
}
else
{
    digitalWrite(_buzz,LOW);
}
}