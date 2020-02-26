#ifndef Pen_h
#define Pen_h

#include "Arduino.h"

class Pen
{
  public:
    Pen();
    void writeLetter(char letter);
    void penDown(boolean penPosition);
    void movePivot(double degrees);
    void moveStraight( double distance);
    void lineBetweenPoints(double x1, double y1, double x2,double y2);
    double currAngle_;
};
#endif
