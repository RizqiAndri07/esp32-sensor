#ifndef SENSOR_H
#define SENSOR_H

#include <DHTesp.h>

extern DHTesp dht;

void setupSensor();       // Tidak perlu parameter lagi
float readTemperature();
float readHumidity();

#endif
