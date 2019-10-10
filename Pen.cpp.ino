#include "Arduino.h"
#include "Pen.h"
#include "alphabet.h"
#include <Stepper.h>

const int step_360 = 200;// 360 number of steps per/rev
                               
// initialize the stepper library on pins 2-5 n 8-11 
Stepper stepMotorX(step_360,2,3,4,5);
Stepper stepMotorY(step_360,8,9,10,11);       


Pen::Pen()
{
  stepMotorX.setSpeed(60);//speed in x direction
  stepMotorY.setSpeed(60);//speed in y direction
  int stepsPerInch = 100; //this is just a guess, need to measure steps to 1 inch, then we can assume that the letters will end up being 1 inch. 

}

void Pen:: writeLetter(char letter)
{
  
}

void Pen::movePen(boolean penPosition)
{
  
}

void Pen:: drawLine(double startx, double starty, double endx, double endy, boolean penPosition)
{
  movPen(penPosition)
  //caluclate the change in x, change in y for each, divide by the larger one to find incrememtns for each

  //calcuate change, convert to steps
  float changeX = (endx - startx) * stepsPerInch; 
  float changeY = (endy -starty) * stepsPerInch; 
  
  //determine which is larger
  float larger = changeY;
  if(changeX > changeY)
  {
   larger = changeX; 
  }
  
  //calculate increments for each.
  float stepXInc =  changeX/larger;
  float stepYInc = ChangeY/larger;

//mover stepper motors along that diagonal line

  float xPos =0;
  float yPos =0;
  for(int i=0; i<larger; i++)
  {
  xPos += stepXInc;
  yPos += stepYInc;
  
  // Move stepper X to stepXPos
  // Move stepper Y to stepYPos
  }
  
}
