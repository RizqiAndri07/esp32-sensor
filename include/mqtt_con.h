#ifndef MQTT_CON_H
#define MQTT_CON_H

#include <WiFiClientSecure.h>
#include <PubSubClient.h>

extern WiFiClientSecure secureClient;
extern PubSubClient client;

void setupMQTT(const char* server, int port, const char* user, const char* pass);
void reconnectMQTT(const char* clientID, const char* user, const char* pass, int LED_MQTT);
void publishMessage(const char* topic, const char* message);

#endif