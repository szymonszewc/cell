#ifndef HT_h
#define HT_h

#include "Arduino.h"
#include <DHT.h>

class HT
{
  public:
    HT(int pin);
    void initialize();
    int changeT();
    int changeH();
    void check(int H, int T);
    int Tcheck();
    int Hcheck();
    private:
    DHT dht;
    int Temperature;
    int Humidity;
    int lastTemperature;
    int lastHumidity;
    int _pin;
};

#endif