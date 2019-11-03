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
    lastTemperature=Temperature;
    Temperature=dht.getTemperature(); 
    if (dht.getStatusString() == "OK") {
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
     return Humidity;
    }
    else
    {
        return lastHumidity;
    }
}