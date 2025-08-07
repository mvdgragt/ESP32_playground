#include "Wire.h"
#include <Arduino.h>

#define TOF10120_ADDR 0x52

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  Wire.begin(21, 22);
  delay(1000);
  Serial.println("TOF10120 starting...");
}

void loop()
{
  Wire.beginTransmission(TOF10120_ADDR);
  Wire.write(0x00); // Command to start reading distance
  Wire.endTransmission();

  Wire.requestFrom(TOF10120_ADDR, 2);
  if (Wire.available() == 2)
  {
    uint8_t highByte = Wire.read();
    uint8_t lowByte = Wire.read();

    int distance = (highByte << 8) + lowByte;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
  }
  else
  {
    Serial.println("Failed to read from TOF10120");
  }
  delay(500);
}
