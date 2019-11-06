#include "Arduino.h"
#include "IF.hpp"
IF::IF(int buzz) : m_lcd(0x27,16,2)
{
    _buzz=buzz;
}
void IF::initialize()
{   
    i_want_to_see=1;
    m_lcd.init();
    m_lcd.begin(16, 2);
    m_lcd.display();
    m_lcd.backlight();
    pinMode(_buzz,OUTPUT);
    digitalWrite(_buzz,LOW);
}
void IF::iter()
{
  i_want_to_see=!i_want_to_see;
}
void IF::backlight()
{
  if(i_want_to_see)
  {
    m_lcd.display();
    m_lcd.backlight();
  }
  else
  {
    m_lcd.noDisplay();
    m_lcd.noBacklight();
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