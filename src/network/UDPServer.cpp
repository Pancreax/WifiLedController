#include "UDPServer.h"

void UDPServer::setup() {
    Udp.begin(localPort);
}

char * UDPServer::receive() {
    while (Udp.parsePacket() <= 0);
    int len = Udp.read(incomingPacket, 255);
    incomingPacket[len] = '\0';
    return incomingPacket;
}