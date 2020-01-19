#include "cFood.h"
#include "time.h"

cFood::cFood(const LiquidCrystal_I2C* L){
    LCD=L;
    FoodLocationV= FoodLocationH = VerticalLocalFood = RandomFoodLocation = 0;
    randomSeed(analogRead(0));
  }
  
void cFood::GenerateFood(){
    FoodLocationV = random(0,1);
    FoodLocationH = random(1,15);
    RandomFoodLocation = random(0,4);
    VerticalLocalFood = random(0,8);
    SpawnFood = false;
}

void cFood::ReturnFood(){
    LCD->setCursor(FoodLocationH, FoodLocationV);
    LCD->write(byte(1));
  }
