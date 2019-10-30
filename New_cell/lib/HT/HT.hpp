#ifndef HT_h
#define HT_h

#include "Arduino.h"
#include <DHT.h>

class HT
{
  public:
    HT(int pin, int buzzer);
    DHT dht;
    void initialize();
    int changeT();
    int changeH();
    int Temperature;
    int Humidity;
    int lastTemperature;
    int lastHumidity;
    int _pin;
    int buzz;
};

#endif