#include "wifi_con.h"
#include "blinker.h"


void connectToWifi(const char* ssid, const char* pass, int LED_WIFI){
    Blinker wifiBlinker(LED_WIFI, 150);
    Serial.print("Menghubungkan ke ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while(WiFi.status() != WL_CONNECTED){
        wifiBlinker.update();
    }
    wifiBlinker.on();
    Serial.println("Terhubung ke :" + String(ssid));
    Serial.print("IP address : ");
    Serial.println(WiFi.localIP());
}