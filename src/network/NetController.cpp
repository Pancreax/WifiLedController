#include "NetController.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>

void NetController::setup() {
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.print(WiFi.localIP()); 
    Serial.println();
}