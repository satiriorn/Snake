#include "cWorld.h"


cWorld::cWorld(const LiquidCrystal_I2C* L){
    LCD = L;
  }
  
void cWorld::CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV){
  uint8_t x = ScaleH*ScaleV;
    for(uint8_t i = 0; i<=28;i++)
      for(uint8_t j = 0; j<8; j++)
        WorldBlocks[i][j] = B00000;
    Create = false;
  }
  
void cWorld::GetValueFood(const uint8_t& FoodLocationV, const uint8_t& FoodLocationH,const uint8_t& RandomFoodLocation,const uint8_t& VerticalLocalFood){
 
  FLV = &FoodLocationV;
  FLH = &FoodLocationH;
  RLV = &RandomFoodLocation;
  VLF = &VerticalLocalFood;
  }
  
void cWorld::ReturnFood(){
  LCD->setCursor(*FLH, *FLV);
  LCD->write(byte(1));
  }
/*  
void cWorld::CheckWorld(const uint8_t &VertGlobal,const uint8_t &HorizontalLocation, byte* ByteSnake, const uint8_t &VerticalLocation){
  UpSnake = false;
   if()
        UpSnake = true;
      }
    }
   else if(VertGlobal == -1||VertGlobal == 2||HorizontalLocation == -1||HorizontalLocation == 16){
       GameOver = true;
      }
  }
  */
