#include "blinker.h"

Blinker::Blinker(int p, unsigned long i) 
  : ledPin(p), interval(i), previousMillis(0), ledState(LOW), pulseActive(false) {
  pinMode(ledPin, OUTPUT);
}

void Blinker::update() {
  unsigned long currentMillis = millis();

  // kalau sedang pulse → matikan setelah durasi selesai
  if (pulseActive && (currentMillis - previousMillis >= interval)) {
    pulseActive = false;
    ledState = LOW;
    digitalWrite(ledPin, LOW);
  }

  // kalau tidak sedang pulse, jalankan blink normal
  if (!pulseActive && (currentMillis - previousMillis >= interval)) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}

void Blinker::on() {
  pulseActive = false;
  ledState = HIGH;
  digitalWrite(ledPin, HIGH);
}

void Blinker::off() {
  pulseActive = false;
  ledState = LOW;
  digitalWrite(ledPin, LOW);
}

void Blinker::sendMessage(unsigned long pulseDuration) {
  pulseActive = true;
  ledState = HIGH;
  digitalWrite(ledPin, HIGH);
  previousMillis = millis();    // catat waktu nyalanya
  interval = pulseDuration;     // lama pulse
}
