#ifndef UDP_SERVER
#define UDP_SERVER

#include <WiFiUdp.h>

class UDPServer {
    public:
        void setup();        
        char * receive();

    private:
        WiFiUDP Udp;
        char incomingPacket[256];
        int localPort = 5005;
};

#endif