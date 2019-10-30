#include "Arduino.h"
#include "HT.hpp"
HT::HT(int pin, int buzzer)
{
    _pin=pin;
    buzz=buzzer;
}
void HT::initialize()
{
    dht.setup(_pin);
}

int HT::changeT()
{
    lastTemperature=Temperature;
    Temperature=dht.getTemperature(); 
    if (dht.getStatusString() == "OK") {
               if((Temperature>30)||Humidity<60){
        digitalWrite(buzz,HIGH);
        }
        else
        {
        digitalWrite(buzz,LOW);
        }
     return Temperature;
    }
    else
    {
        return lastTemperature;
    }
}
int HT::changeH()
{
        lastHumidity=Humidity;
    Humidity=dht.getHumidity(); 
    if (dht.getStatusString() == "OK") {
        if((Humidity<60)||Temperature>30){
        digitalWrite(buzz,HIGH);
        }
        else
        {
        digitalWrite(buzz,LOW);
        }
     return Humidity;
    }
    else
    {
        return lastHumidity;
    }
}