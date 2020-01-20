#include "cWorld.h"



cWorld::cWorld(const LiquidCrystal_I2C* L, const cFood* F){
    LCD = L;
    Food = F;
  }
  
void cWorld::CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV){
  int x = ScaleH*ScaleV;
    for(uint8_t i = 0; i<=x;i++){
      for(uint8_t j = 0; j<8; j++){
        WorldBlocks[i][j] = B00000;
        }}
    Create = false;
  }
  
void cWorld::MergeFood(){
    WorldBlocks[Food->FoodLocationH][Food->VerticalLocalFood] += Food->Foods[Food->VerticalLocalFood];
  }
     
void cWorld::DrawingUnits(){
    Food->ReturnFood();
  }
/*
void cWorld::CheckWorld(const uint8_t &VertGlobal,const uint8_t &HorizontalLocation, byte* ByteSnake, const uint8_t &VerticalLocation){
  UpSnake = false;
   if(Food->FoodLocationV==VertGlobal&&Food->FoodLocationH==HorizontalLocation){
      ByteSnake[Food->VerticalLocalFood] |= (1<<Food->RandomFoodLocation); 
      if(WorldBlocks[VerticalLocation] == WorldBlocks[Food->VerticalLocalFood]&&VerticalLocation==Food->VerticalLocalFood){
        Food->GenerateFood();
        UpSnake = true;
      }
    }
   else if(VertGlobal == -1||VertGlobal == 2||HorizontalLocation == -1||HorizontalLocation == 16){
       GameOver = true;
      }
  }
*/
