#include "cFood.h"
#include "time.h"

cFood::cFood(const LiquidCrystal_I2C* L){
    LCD=L;
    CursorLocationV = CursorLocationH = arrLocation = RandomPixelLocation = 0;
    randomSeed(analogRead(0));
  }
  
void cFood::GenerateFood(){
  if(CursorLocationH > 0){
    Foods[arrLocation]&= ~(1 << RandomPixelLocation);
    }
    CursorLocationV = random(0,1);
    CursorLocationH =random(1,15);
    RandomPixelLocation = 4;//random(0,4);
    arrLocation = random(0,8);
    Foods[arrLocation] |= (1<<RandomPixelLocation);
    LCD->createChar(1,Foods); 
    LCD->setCursor(CursorLocationH, CursorLocationV);
    LCD->write(byte(1));
    SpawnFood = false;
}

void cFood::ReturnFood(){
    LCD->setCursor(CursorLocationH, CursorLocationV);
    LCD->write(byte(1));
  }
