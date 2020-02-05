
#include "Arduino.h"
#include "Pen.h"

  Pen mypen;
  
void setup() {
  Serial.begin(9600);
}

void loop() {
  mypen.drawLine(0,0,0,1,1);
  
}
