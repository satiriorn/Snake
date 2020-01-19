#include "cWorld.h"

cWorld::cWorld(const LiquidCrystal_I2C* L, const cFood* F){
    LCD = L;
    Food = F;
  }

void cWorld::CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV){
  int x = ScaleH*ScaleV;
    for(uint8_t i = 0; i<=x;i++){
      for(uint8_t j = 0; j<8; j++){
        WorldBlocks[i][j] = B00000;}}
    Create = false;
  }
  
void cWorld::MergeFood(){
  LCD->createChar(0,WorldBlocks[1]);
  LCD->setCursor(2, 1);
  WorldBlocks[1][0] |= (1<<2); 
  Serial.print(WorldBlocks[1][0]);
  LCD->write(byte(0));
  delay(4000);
  }
/*
void cWorld::CheckWorld(const uint8_t &VertGlobal,const uint8_t &HorizontalLocation, byte* ByteSnake, const uint8_t &VerticalLocation){
  UpSnake = false;
   if(Food->FoodLocationV==VertGlobal&&Food->FoodLocationH==HorizontalLocation){
      ByteSnake[Food->VerticalLocalFood] |= (1<<Food->RandomFoodLocation); 
      if(WorldBlocks[VerticalLocation] == WorldBlocks[Food->VerticalLocalFood]&&VerticalLocation==Food->VerticalLocalFood){
        UpSnake = true;
      }
    }
   else if(VertGlobal == -1||VertGlobal == 2||HorizontalLocation == -1||HorizontalLocation == 16){
       GameOver = true;
      }
  }
   
void cWorld::DrawingUnits(bool Horizontal=false, const uint8_t &HorizontalLocation = 0, const uint8_t &VertGlobal = 0){
  if(Horizontal){
    //LCD->clear();
    //Food->ReturnFood();
    LCD->setCursor(HorizontalLocation,VertGlobal);
  }
  else{
     // food->ReturnFood();
    }
  }*/
