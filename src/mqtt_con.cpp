#include "mqtt_con.h"
#include "blinker.h"

WiFiClientSecure secureClient;
PubSubClient client(secureClient);

void setupMQTT(const char* server, int port, const char *user, const char* pass){
    secureClient.setInsecure();
    client.setServer(server, port);  
};

void reconnectMQTT(const char* clientID, const char* user, const char* pass,int LED_MQTT){
    Blinker mqttBlinker(LED_MQTT, 100);
    Serial.print("Menghubungkan ke MQTT...");
    while(!client.connected()){
        if(client.connect(clientID, user, pass)){
            Serial.println("Terhubung");
            mqttBlinker.on();
        }else{
            Serial.print("gagal, rc=");
            Serial.print(client.state());
            Serial.println(" coba lagi dalam 5 detik");
            delay(5000);
        }
    }
}

void publishMessage(const char* topic, const char* message){
    if(client.connected()){
        client.publish(topic, message);
        Serial.println("Pesan terkirim : " + String(message));
    }else{
        Serial.println("Gagal mengirim pesan tidak terhubung ke mqtt");
    }
}
