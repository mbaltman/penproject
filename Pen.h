#indef Pen_h
#define Pen_h

#include "Arduino.h"

class Pen
{
  public:
    Pen();
    void writeLetter(char letter);
  private:
    void movePen(boolean penPosition);
    void drawLine(double startx, double starty, double endx, double endy, boolean penPosition);
    
  
}
#endif
