#ifndef BLINKER_H
#define BLINKER_H

#include <Arduino.h>

class Blinker {
  private:
    int ledPin;
    unsigned long previousMillis;
    unsigned long interval;
    bool ledState;
    bool pulseActive;

  public:
    Blinker(int p, unsigned long i);
    void update();
    void on();
    void off();
    void sendMessage(unsigned long pulseDuration = 100);
};

#endif
