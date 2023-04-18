#include <Arduino.h>
#include <Controllino.h>

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 10; i++)
  {
    pinMode(CONTROLLINO_R0 + i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(CONTROLLINO_R0 + i, 1);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(CONTROLLINO_R0 + i, 0);
    delay(100);
  }
}