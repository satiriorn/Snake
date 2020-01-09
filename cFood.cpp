#include "cFood.h"
#include "time.h"

cFood::cFood(const LiquidCrystal_I2C* L){
    LCD=L;
    randomSeed(analogRead(0));
  }
int cFood::RandomNumber(const int& value){
   srand(time(NULL));
   return 1 + rand() % value;
  }
void cFood::GenerateFood(){
    CursorLocationV = RandomNumber(random(0,2));
    CursorLocationH = RandomNumber(random(1,15));
    RandomPixelLocation = mass[RandomNumber(random(0,4))];
    arrLocation = RandomNumber(random(0,8));
    Foods[arrLocation] = RandomPixelLocation;
    LCD->createChar(1,Foods); 
    LCD->setCursor(CursorLocationH, CursorLocationV);
    LCD->write(byte(1));
    SpawnFood = false;
}

void cFood::ReturnFood(){
    LCD->setCursor(CursorLocationH, CursorLocationV);
    LCD->write(byte(1));
  }
