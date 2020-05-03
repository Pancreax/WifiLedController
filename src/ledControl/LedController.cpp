#include <Arduino.h>
#include "linearizerArray.h"
#include "LedController.h"

void LedController::setup() {
    setBrightness(0);
}

void LedController::setBrightness(char * brightness) {
    int intBrightness = (int)strtol((const char*)brightness, NULL, 10);
    setBrightness(intBrightness);
}

void LedController::setBrightness(int brightness) {
    if(brightness < 0) brightness = 0;
    if(brightness > 1023) brightness = 1023;
    currentBrightness = brightness;
    analogWrite(ledPin, getLinearizedBrightness(currentBrightness));
}

int LedController::getBrightness() {
    return currentBrightness;
}

int LedController::getLinearizedBrightness(int desiredBrightness) {
    return linearizerArray[desiredBrightness];
}