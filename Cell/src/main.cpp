#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal.h>
#define light 10
#define led 11
#define buzzer 12
#define interrupt 2
#define DHT_PIN 3

int Humidity;
int Temperature;
DHT dht;
LiquidCrystal lcd(4,5,6,7,8,9);
boolean i_want_to_see;
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
  dht.setup(DHT_PIN);
  pinMode(interrupt,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(light,OUTPUT);
  digitalWrite(buzzer,LOW);
  digitalWrite(led,LOW);
  lcd.begin(16, 2);
  i_want_to_see=1;
  digitalWrite(light,i_want_to_see);
attachInterrupt(digitalPinToInterrupt(interrupt), backlight, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  Humidity=dht.getHumidity();
  Temperature=dht.getTemperature();
   if (dht.getStatusString() == "OK") {
     lcd.setCursor(0,0);
     lcd.print(Humidity);
     lcd.print("%");
     lcd.setCursor(0,1);
     lcd.print(Temperature);
     lcd.print("*C");
  if((Temperature>30)||(Humidity<60))
    {
     digitalWrite(buzzer,HIGH);
     digitalWrite(led,HIGH);
    }
  else
    {
       digitalWrite(buzzer,LOW);
       digitalWrite(led,LOW);
    }
   }  
  delay(1000);
}