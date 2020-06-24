#include <SoftwareSerial.h>

#define ARDUINO_GPS_RX 7 // Arduino RX pin connected to GPS TX
#define ARDUINO_GPS_TX 8 // Arduino TX pin connected to GPS RX
#define GPS_BAUD_RATE 9600 // The GPS Shield module defaults to 9600 baud

SoftwareSerial gpsPort(ARDUINO_GPS_TX, ARDUINO_GPS_RX);

void setup() {
  // put your setup code here, to run once:
  gpsPort.begin(GPS_BAUD_RATE);
  Serial.begin(9600);
  Serial.write("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (gpsPort.available()) // If GPS data is available
  {
    Serial.write(gpsPort.read()); // Read it and print to SerialMonitor
    Serial.write("Yeet\n");
  }
  if (Serial.available()) // If SerialMonitor data is available
    gpsPort.write(Serial.read()); // Read it and send to GPS
}
