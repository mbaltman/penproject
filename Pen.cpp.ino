#include "Arduino.h"
#include "Pen.h"
#include <Stepper.h>
#include <Servo.h> 
#include "Pen.h"

const int step_360 = 200;// 360 number of steps per/rev
                               
// initialize the stepper library on pins 2-5 n 8-11 
Stepper stepMotorL(step_360,4,5,6,7);
Stepper stepMotorR(step_360,8,9,10,11); 
Servo penServo; 
int stepsPerInch = 100; //this is just a guess, need to measure steps to 1 inch, then we can assume that the letters will end up being 1 inch.     

Pen::Pen()
{
  stepMotorL.setSpeed(60);//speed in x direction
  stepMotorR.setSpeed(60);//speed in y direction
  penServo.attach(3); // attach the servo to pin 6 
  currAngle_ = 0; 
}

void Pen::penDown(bool penPosition)
{
  if(penPosition)
    penServo.write(110);           
  else
    penServo.write(150);            
}


//pivot the robot around the center point, positive number corresponds to turning right and negative corresponds to tunring left. 
void Pen::movePivot(double degree)
{
   Serial.print("changing angle by " ); 
   Serial.println(degree);
    currAngle_ = currAngle_ + degree;

    
    //some conversion between how much we want to pivot and how many times it needs to step and the size of the steps.
    int stepSize =10;
    int iterations = abs(degree);
    
    //this will make stepSize negative if degrees is negative
     stepSize = stepSize * (degree/ abs(degree));
    for(int i=0; i<iterations; i++){
  
    //move them in opposite directions
    stepMotorL.step(stepSize); 
    stepMotorR.step(stepSize * -1);
  }
  return;
    
}

void Pen::moveStraight(double distance)
{
   Serial.print("moving distance ");
   Serial.println(distance); 
  //some conversion between how far we want to move and the distacne passed in. 
  int stepSize =200;
  int iterations = abs(distance);
    
  //this will make stepSize negative if distance is negative
  stepSize = stepSize * (distance/ abs(distance));
    
  for(int i=0; i<iterations; i++)
  {
  //move them in same direction
    stepMotorL.step(stepSize);
    delay(500); 
    stepMotorR.step(stepSize);
  }
  return;
    
}

void Pen::lineBetweenPoints(double x1,double y1, double x2, double y2)
{
  Serial.println("change angle"); 
  double newAngle = atan((y2-y1)/(x2-x1));
  movePivot(newAngle-currAngle_);

  Serial.println("move straight"); 
  double distance = sqrt(sq(x2-x1) + sq(y2-y1));
  moveStraight(distance);
  
}

                               
