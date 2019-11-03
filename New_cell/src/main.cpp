#include <Arduino.h>
#include <HT.hpp>
#include <IF.hpp>
#define light 10
#define buzzer 11
#define interrupt 2
#define DHT_PIN 3
HT ht(DHT_PIN);
IF If(4,5,6,7,8,9,light,buzzer);
void backlight()
{
  If.backlight();
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
If.display(ht.changeH(),ht.changeT());
delay(1000);
}