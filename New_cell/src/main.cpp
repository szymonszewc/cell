#include <Arduino.h>
#include <HT.hpp>
#include <LiquidCrystal.h>
#define light 11
#define buzzer 10
#define interrupt 2
#define DHT_PIN 3
LiquidCrystal lcd(4,5,6,7,8,9);
boolean i_want_to_see;
boolean contrast;
HT ht(DHT_PIN,buzzer);
void backlight()
{
  i_want_to_see=!i_want_to_see;
  digitalWrite(light,i_want_to_see);
  if(i_want_to_see)
  {
    lcd.display();
  }
  else
  {
    lcd.noDisplay();
  }
  
}
void setup() {
  // put your setup code here, to run once:
  pinMode(interrupt,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(light,OUTPUT);
  digitalWrite(buzzer,LOW);
  lcd.begin(16, 2);
  i_want_to_see=1;
  contrast=1;
  digitalWrite(light,i_want_to_see);
attachInterrupt(digitalPinToInterrupt(interrupt), backlight, FALLING);
ht.initialize();
}
void loop() {
  // put your main code here, to run repeatedly:
     lcd.setCursor(0,0);
     lcd.print(ht.changeH());
     lcd.setCursor(2,0);
     lcd.print("%");
     lcd.setCursor(0,1);
     lcd.print(ht.changeT());
     lcd.setCursor(2,1);
     lcd.print("*C");
  delay(1000);
}