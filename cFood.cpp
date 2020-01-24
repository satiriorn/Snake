#include "cFood.h"
#include "time.h"

cFood::cFood(const LiquidCrystal_I2C* L, const cWorld* W){
  LCD = L;
  World = W;
  FoodLocationV = FoodLocationH = VerticalLocalFood = RandomFoodLocation = 0;
  randomSeed(analogRead(0));
}

void cFood::GenerateFood(){
  FoodLocationV = random(0,1);
  FoodLocationH = random(1,15);
  RandomFoodLocation =2;// random(0,4);
  VerticalLocalFood = random(0,8);
  Drawing();
  World->GetValueFood(FoodLocationV, FoodLocationH, RandomFoodLocation, VerticalLocalFood);
}

void cFood::Drawing(){
  World->WorldBlocks[FoodLocationH][VerticalLocalFood]|= (1<<RandomFoodLocation); 
  LCD->createChar(7,World->WorldBlocks[FoodLocationH]);
  LCD->setCursor(FoodLocationH, FoodLocationV);
  LCD->write(byte(7)); 
}
