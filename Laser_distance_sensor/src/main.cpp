#include <Arduino.h>
#include <Wire.h>

uint16_t distance;

void setup() {
  Serial.begin(115200);
  Wire.begin(22, 21); 
  Wire.beginTransmission(0x29);
  Wire.write(0x00);     
  Wire.write(0x02);    
  Wire.endTransmission();

}

void loop() {
  Wire.beginTransmission(0x29);
  Wire.write(0x1E);
  Wire.endTransmission(false); 
  Wire.requestFrom(0x29, 2);
  if (Wire.available() == 2) {
    distance = (Wire.read() << 8) | Wire.read();
    float value = (float)((int)distance);
    Serial.println(value);
  } 

}
