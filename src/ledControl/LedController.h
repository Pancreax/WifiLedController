#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

class LedController {
    public:
        void setup();
        void setBrightness(char * brightness);
        void setBrightness(int brightness);
        int getBrightness();

    private:
        const int ledPin = 14;
        int currentBrightness = 0;

        int getLinearizedBrightness(int desiredBrightness);
};

#endif