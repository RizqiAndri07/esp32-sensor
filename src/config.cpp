#include "config.h"
#include "secrets.h"

// GPIO pins (tetap di sini)
const int SENSOR_PIN = 18;
const int LED_WIFI = 25;
const int LED_MQTT = 27;
const int LED_PUB = 13;

// Network config (dari secrets.h)
const char* WIFI_SSID = WIFI_SSID_VALUE;
const char* WIFI_PASSWORD = WIFI_PASSWORD_VALUE;

const char* MQTT_SERVER = MQTT_SERVER_VALUE;
const int MQTT_PORT = MQTT_PORT_VALUE;
const char* MQTT_USER = MQTT_USER_VALUE;
const char* MQTT_PASS = MQTT_PASS_VALUE;
const char* CLIENT_ID = CLIENT_ID_VALUE;
const char* MQTT_TOPIC = MQTT_TOPIC_VALUE;