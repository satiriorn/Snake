#include "cWorld.h"

cWorld::cWorld(const LiquidCrystal_I2C* L){
  LCD = L;
  GameOver = UpSnake = false;
  SpawnFood = Create = true;
}
  
void cWorld::CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV){//Initializing an array of the world
  uint8_t x = ScaleH*ScaleV;
    for(uint8_t i = 0; i<=x;i++)
      for(uint8_t j = 0; j<8; j++)
        WorldBlocks[i][j] = B00000;
   Create = false;
}
  
void cWorld::GetValueFood(const uint8_t& FoodLocationV, const uint8_t& FoodLocationH,const uint8_t& RandomFoodLocation,const uint8_t& VerticalLocalFood){//Getting a food location on LCD
  FLV = &FoodLocationV;
  FLH = &FoodLocationH;
  RLV = &RandomFoodLocation;
  VLF = &VerticalLocalFood;
  SpawnFood = false;
}
  
void cWorld::ReturnFood(){//Drawing food while cleaning the screen                      
  LCD->setCursor(*FLH, *FLV);
  LCD->write(byte(7));
}

void cWorld::CheckWorld(const uint8_t &VertGlobal,const uint8_t &HorizontalLocation, const uint8_t &VerticalLocation, const uint8_t &HeadSnake){
  UpSnake = SpawnFood = false;
    if(VertGlobal == *FLV && HorizontalLocation == *FLH && VerticalLocation == *VLF && HeadSnake == *RLV){              //Snake size increase
     SpawnFood = UpSnake =true;
     Score++;
  }
  else if(VertGlobal == -1||VertGlobal == 2||VertGlobal == 255||HorizontalLocation == -1||HorizontalLocation == 16)    //Going abroad in which the player loses
    GameOver = true;
}
