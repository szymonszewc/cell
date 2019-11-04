#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define buzzer 9
#define led 10
#define interrupt 2
#define DHT_PIN 3

int Humidity;
int Temperature;
DHT dht;
LiquidCrystal_I2C lcd(0x27, 16,2);
boolean i_want_to_see;
void backlight()
{
  i_want_to_see=!i_want_to_see;
  if(i_want_to_see)
  {
    lcd.display();
    lcd.backlight();
  }
  else
  {
    lcd.noDisplay();
    lcd.noBacklight();
  }
  
}
void setup() {
  // put your setup code here, to run once:
  dht.setup(DHT_PIN);
  pinMode(interrupt,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  digitalWrite(buzzer,LOW);
  digitalWrite(led,LOW);
  lcd.init();
  lcd.begin(16, 2);
  lcd.display();
  lcd.backlight();
  i_want_to_see=1;
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