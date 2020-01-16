#include "cWorld.h"

cWorld::cWorld(const LiquidCrystal_I2C* L, const cFood* F){
    LCD = L;
    Food = F;
  }
  
void cWorld::DrawingUnits(bool Horizontal=false, const uint8_t &HorizontalLocation = 0, const uint8_t &VertGlobal = 0){
  if(Horizontal){
    LCD->clear();
    Food->ReturnFood();
    LCD->setCursor(HorizontalLocation,VertGlobal);
  }
  else{
      LCD->clear();
      Food->ReturnFood();
    }
  }
void cWorld::CreateWorld(const uint8_t &ScaleH, const uint8_t &ScaleV){
  int x = ScaleH*ScaleV;
    for(uint8_t i = 0; i<=x;i++){
      for(uint8_t j = 0; j<8; j++){
        WorldBlocks[i][j] = B00000;
        }
    }
    Create = false;
  }
  
void cWorld::CheckWorld(const uint8_t &VertGlobal,const uint8_t &HorizontalLocation, byte* ByteSnake, const uint8_t &VerticalLocation){
  UpSnake = false;
   if(Food->CursorLocationV==VertGlobal&&Food->CursorLocationH==HorizontalLocation){
      ByteSnake[Food->arrLocation] |= (1<<Food->RandomPixelLocation); 
      if(ByteSnake[VerticalLocation] == Food->Foods[Food->arrLocation]&&VerticalLocation==Food->arrLocation){
        Food->GenerateFood();
        UpSnake = true;
      }
    }
   else if(VertGlobal == -1||VertGlobal == 2||HorizontalLocation == -1||HorizontalLocation == 16){
       GameOver = true;
      }
  }
  
