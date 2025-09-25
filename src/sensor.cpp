#include "sensor.h"
#include "config.h"  // ✅ supaya bisa baca SENSOR_PIN

DHTesp dht;

void setupSensor() {
  dht.setup(SENSOR_PIN, DHTesp::DHT22);  // ✅ langsung pakai dari config.h
}

float readTemperature() {
  return dht.getTemperature();
}

float readHumidity() {
  return dht.getHumidity();
}
