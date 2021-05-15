// code stolen from: https://stackoverflow.com/questions/49763827/why-isnt-my-arduino-code-printing-latitude-and-longitude-to-the-serial-monitor
// If you want to try it, NeoGPS is available from the Arduino Library Manager
// under the menu Sketch-> Include Library-> Manage Libraries, or from the link above. 
// Also, NeoGPS is smaller, faster, more reliable and more accurate than all other libraries.

// this code is working (21.12.2018)
// got long and lat
// Position: lat: 4x.223099 lon: 1x.331287 (x for anonymisation)

// Todo: // Extract and print negative sign "if (degE7 < 0) {" 
//like in: https://github.com/SlashDevin/NeoGPS/blob/master/examples/NMEAloc/NMEAloc.ino

// get information about what data is available her:
// https://github.com/SlashDevin/NeoGPS/blob/master/extras/doc/Data%20Model.md
// fix.speed_kph(), in floating-point kilometers per hour
// fix.altitude_cm(), in integer centimeters
// fix.satellites, a satellite count

#include <NMEAGPS.h>

NMEAGPS gps; // create gps object

void setup() {
  Serial.begin(9600); // connect serial
  Serial1.begin(9600); // default for most is 9600
  Serial.println("\nTest");
}

void loop() {

  if (gps.available( Serial1 )) {
    // get the structure that contains all the parsed values
    gps_fix fix = gps.read();

    // display position
    Serial.print("Position: ");
    if (fix.valid.location) {
      Serial.print("lat: "); Serial.print( fix.latitude(), 6 ); Serial.print(" ");
      Serial.print("lon: "); Serial.println( fix.longitude(), 6 );
    } else {
      Serial.println( '?' );
    }
  }
}
