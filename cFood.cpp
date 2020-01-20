#include "cFood.h"
#include "time.h"

cFood::cFood(const LiquidCrystal_I2C* L){
    LCD=L;
    FoodLocationV= FoodLocationH = VerticalLocalFood = RandomFoodLocation = 0;
    randomSeed(analogRead(0));
  }
  
void cFood::GenerateFood(){
    if(FoodLocationH > 0){
    Foods[VerticalLocalFood]&= ~(1 << RandomFoodLocation);
    }
    FoodLocationV =1;// random(0,1);
    FoodLocationH =2; //random(1,15);
    RandomFoodLocation = random(0,4);
    VerticalLocalFood = random(0,8);
    Foods[VerticalLocalFood]|= (1<<RandomFoodLocation); 
    LCD->createChar(1,Foods);
    LCD->setCursor(FoodLocationH, FoodLocationV);
    LCD->write(byte(1)); 
    SpawnFood = false;
}

void cFood::ReturnFood(){
    LCD->createChar(1,Foods);
    LCD->setCursor(FoodLocationH, FoodLocationV);
    LCD->write(byte(1));
  }
