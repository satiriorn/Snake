#include "cFood.h"


cFood::cFood(const LiquidCrystal_I2C* L){
    LCD=L;
  }
  
int cFood::getRandomNumber(int Min, int Max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (Max - Min + 1) + Min);
}

void cFood::GenerateFood(){
    CursorLocationV = getRandomNumber(0,1);
    CursorLocationH = getRandomNumber(1,15);
    RandomPixelLocation = mass[getRandomNumber(0,4)];
    Foods[1] = RandomPixelLocation;
    LCD->createChar(1,Foods); 
    LCD->setCursor(CursorLocationH, CursorLocationV);
    LCD->write(byte(1));
    SpawnFood = false;
}

void cFood::ReturnFood(){
    LCD->setCursor(CursorLocationH, CursorLocationV);
    LCD->write(byte(1));
  }
