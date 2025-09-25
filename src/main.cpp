#include <Arduino.h>
#include "wifi_con.h"
#include "mqtt_con.h"
#include "config.h"
#include "sensor.h"

unsigned long lastMsg = 0;

void setup(){
  Serial.begin(115200);
  
  connectToWifi(WIFI_SSID, WIFI_PASSWORD, LED_WIFI);
  setupMQTT(MQTT_SERVER, MQTT_PORT, MQTT_USER, MQTT_PASS);
  reconnectMQTT(CLIENT_ID, MQTT_USER, MQTT_PASS, LED_MQTT);
  setupSensor(); 
  delay(2000); 
}

void loop(){
  if (!client.connected()){
    reconnectMQTT(CLIENT_ID, MQTT_USER, MQTT_PASS, LED_MQTT);
  }
  client.loop();
  double temperature = readTemperature();
  double humidity = readHumidity();
  unsigned long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    String msg = "{\"temperature\": " + String(temperature, 2) + ", \"humidity\": " + String(humidity, 2) + "}";
    Serial.println("Pesan terkirim: " + msg);
    publishMessage(MQTT_TOPIC, msg.c_str());
  }
}