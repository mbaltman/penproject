#indef Pen_h
#define Pen_h

#include "Arduino.h"

class Pen
{
  public:
    Pen();
    void writeLetter();
  private:
    void movePen();
    void drawLine(double startx, double starty, double endx, double endy, boolean penPosition);
    
  
}
#endif
