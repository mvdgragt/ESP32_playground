/*
This is a basic code to test if Your Waveshare Lasersensor works.
Our goal is to create a timing gate so we won't use it as it is not reliable.
Our athletes will be further away than 80cm from the laser which makes the laser too weak
to detect a athlete running past.
*/
#include <Arduino.h>

// put function declarations here:
int laserPin = 22;

void setup()
{
  // put your setup code here, to run once:
  pinMode(laserPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (digitalRead(laserPin) == LOW)
  {
    Serial.println("Obstacles");
  }
  else
  {
    Serial.println("No Obstacles");
  }
  // delay(500);
}

// put function definitions here:
/*
int myFunction()
{
}
*/