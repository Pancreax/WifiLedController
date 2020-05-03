# Wifi Led Controller

**Firmware for a ESP8266 board to control a LED Reflector via Wifi**

This is part of a project of a wifi dimmer/wakeup light LED reflector.
The device will be controlled and configured by an Android App (I'll post it here soon) and maybe by an HTML/JS page hosted in the device too.

## Current Features
- Connects to wifi.
- UDP Basic packet receiving.
- Controls the reflector's brightness via PWM.
- Linearization of brightness curve of the LED for pleasent controlling experience.

## Hardware
I will post something here in near future. For now, it's possible to test this by connecting a LED (driven by a transistor) to any digital GPIO of the ESP8266. Sending UDP Packets to the board will change the brightness of the LED.

## How to use
- Change the wifi SSID and Password in the [NetController.h](./src/network/NetController.h) file so it can reach some wifi network.
- Change the pin in which the LED is connected in the [LedController.h](./src/ledControl/LedController.h)
- Program the ESP8266 and run. It should print something like this in the serial monitor:
```
Connecting to <wifi SSID>
.......
Connected with IP: 192.168.1.100
```
- Send via UDP packets numbers in string format from 0 to 1023 and it will adjust the brightness of the LED accordingly. 0 means minimum and 1023 means maximum brightness.

**Note:** The value from 0 to 1023 is mapped to another value from 0 to 1023 to be sent to PWM Pin. I made this mapping by mannualy adjusting an exponential curve to one that i thought to seem visually nice. More details on that comming soon.

## Todo
 - DNS to be easily found in the wifi network
 - Allow control via websocket along with UDP for html/JS integration
 - Work also as a Access Point
 - Implement a clock that adjusts itself via internet
 - UDP Interface to set the clock and alarm configuration 
 - Implement HTML/JS page to control and configuration.

## Tools
 - ESP-12E Module (any ESP8266 module should work)
 - VSCode
 - [PlatformIO IDE for embedded development](https://platformio.org/) (OMG this is so awesome!)
 - Arduino SDK
