#include <Arduino.h>
#include <HT.hpp>
#include <IF.hpp>
#define buzzer 10
#define interrupt 2
#define DHT_PIN 3
unsigned long acTime;
unsigned long Time;
unsigned long dTime;
int n;
HT ht(DHT_PIN);
IF If(buzzer);
void backlight()
{
  If.i_want_to_see=!If.i_want_to_see;
}
void setup() {
  // put your setup code here, to run once:
  pinMode(interrupt,INPUT);
  ht.initialize();
  If.initialize();
  attachInterrupt(digitalPinToInterrupt(interrupt), backlight, FALLING);
}
void loop() {
  // put your main code here, to run repeatedly:
while (acTime<=4,294,967,280)
{
  acTime=(millis()-(4,294,967,280*n));
  dTime=acTime-Time;
  if(dTime>=1000){
  If.display(ht.changeH(),ht.changeT());
    Time=acTime; 
  }
  If.backlight();
  n++;
}
}