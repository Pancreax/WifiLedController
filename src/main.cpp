#include <Arduino.h>
#include "ledControl/LedController.h"
#include "network/NetController.h"
#include "network/UDPServer.h"

LedController ledController = LedController();
NetController netController = NetController();
UDPServer udpServer = UDPServer();

void setup() {
    Serial.begin(9600);
    delay(200);
    Serial.println();
    Serial.println();

    netController.setup();
    udpServer.setup();
    ledController.setup();
}

void loop() {
    ledController.setBrightness(udpServer.receive());
}