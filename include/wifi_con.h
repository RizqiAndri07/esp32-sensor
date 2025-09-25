#ifndef WIFI_CON_H
#define WIFI_CON_H

#include <WiFi.h>

void connectToWifi(const char* ssid, const char* password, int LED_WIFI);

#endif