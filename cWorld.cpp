#include "cWorld.h"


cWorld::cWorld(const LiquidCrystal_I2C* L){
  LCD = L;
  GameOver = UpSnake = false;
  SpawnFood = Create = true;
}
  
void cWorld::CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV){
  uint8_t x = ScaleH*ScaleV;
    for(uint8_t i = 0; i<=32;i++)
      for(uint8_t j = 0; j<8; j++)
        WorldBlocks[i][j] = B00000;
    Create = false;
}
  
void cWorld::GetValueFood(const uint8_t& FoodLocationV, const uint8_t& FoodLocationH,const uint8_t& RandomFoodLocation,const uint8_t& VerticalLocalFood){
  FLV = &FoodLocationV;
  FLH = &FoodLocationH;
  RLV = &RandomFoodLocation;
  VLF = &VerticalLocalFood;
  SpawnFood = false;
}
  
void cWorld::ReturnFood(){
  LCD->setCursor(*FLH, *FLV);
  LCD->write(byte(7));
}
  
void cWorld::CheckWorld(const uint8_t &VertGlobal,const uint8_t &HorizontalLocation, const uint8_t &VerticalLocation, const uint8_t &HeadSnake){
  UpSnake = SpawnFood = false;
   if(VertGlobal == *FLV && HorizontalLocation == *FLH && VerticalLocation == *VLF && HeadSnake == *RLV){
        SpawnFood = UpSnake =true;
    }
   else if(VertGlobal == -1||VertGlobal == 2||HorizontalLocation == -1||HorizontalLocation == 16){
       GameOver = true;
    }
}
