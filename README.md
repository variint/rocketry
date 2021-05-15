## Pins: 
Arduino Due – GPS Module (2018/19 - not connected to rocket yet)

I used 4 cables: TX, RX, +V, GND

18 TX1 – RXD 

19 RX1 – TXD 

don't need the PPS

## Connection Type: 
UART, don't need a library, Arduino due is capable of doing that 

## Libraries for module: 
NeoGPS – I used NMEAloc of their examples for testing 

## Getting Started: 
* Download NeoGPS library from github 
https://github.com/SlashDevin/NeoGPS 

* Baud rate of our module is 9600 

* Make yourself familiar with cold start / warm start / hot start (TTFF) 

(german link: http://gps-camera.eu/wissen/29-hardware/66-gps-wissen-kaltstart-warmstart-wie-lange-braucht-ein-gps-zum-starten.html) 

In general, a cold start appears, when the GPS module was not connected for a long time, it needed ½ hour the first time we tested it to find GPS sattelites 

You can use software provided by ublox to test it (I liked the visualisation): https://www.u-blox.com/en/product/u-center 

Warm and hot starts are much faster – when the module already knows, where it is (no big change of position since the last start)  

When initialising, go away from houses, trees, car roofs – you should have a clear view to the sky 

* Open example project of the library "NMEAloc" for testing, you may need to change pins in the header file GPSport.h, that file is in src (in this case, I think you don’t include the library, but work inside t downloaded library - need to figure that out) 

> // Default Arduino RX pin number that is connected to the GPS TX pin 

> #ifndef RX_PIN 

> #define RX_PIN 19 

> #endif 

> // Default Arduino TX pin number that is connected to the GPS RX pin 

> #ifndef TX_PIN 

> #define TX_PIN 18 

> #endif
