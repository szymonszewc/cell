#include "Arduino.h"
#include "HT.hpp"
HT::HT(int pin)
{
    _pin=pin;
}
void HT::initialize()
{
    dht.setup(_pin);
}

int HT::changeT()
{
    Temperature=dht.getTemperature(); 
    if (dht.getStatusString() == "OK") {
     return Temperature;
    }
    else
    {
        delay(1000);
        Temperature=dht.getTemperature(); 
        return Temperature;
    }
}
int HT::changeH()
{
    Humidity=dht.getHumidity(); 
    if (dht.getStatusString() == "OK") {
     return Humidity;
    }
    else
{
        delay(1000);
        Humidity=dht.getHumidity(); 
        return Humidity;
}
}