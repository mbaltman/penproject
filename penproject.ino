<<<<<<< HEAD

#include "Arduino.h"
#include "Pen.h"

  Pen mypen;
  
void setup() {
  Serial.begin(9600);
}

void loop() {
  mypen.drawLine(0,0,0,1,1);
  
}
=======
#include "pen.h" 
>>>>>>> 531fca24394f7dce31141e71781360e9d1bfa834
