#include <Stepper.h> 
const int stepsPerRevolution = 200;  // change to fit number of steps per revolution 
// initialize the stepper library on pins 8 through 11: 
Stepper myStepper1(stepsPerRevolution, 8, 9, 10, 11); 
//Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7); 
void setup() { 
  myStepper1.setSpeed(60); 
  //myStepper2.setSpeed(60); 
  // initialize the serial port: 
  Serial.begin(9600); 
} 
void loop() { 
  // step one revolution  in one direction: 
  Serial.println("clockwise"); 
  myStepper1.step(stepsPerRevolution); 
  //myStepper2.step(-stepsPerRevolution); theoretically something like this is a loop would make the dude spin 
  delay(500); 
  // step one revolution in the other direction: 
  Serial.println("counterclockwise"); 
  myStepper1.step(-stepsPerRevolution); 
  //myStepper2.step(stepsPerRevolution); 
  delay(500); 
} 
