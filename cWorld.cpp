#include "cWorld.h"

cWorld::cWorld(const LiquidCrystal_I2C* L,const cFood* F){
    LCD = L;
    Food = F;
  }
  
void cWorld::DrawingUnits(bool Horizontal=false, const int &HorizontalLocation = 0, const int &VertGlobal = 0){
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
  
void cWorld::CheckWorld(const int &VertGlobal,const int &HorizontalLocation, byte* ByteSnake, const int &VerticalLocation){
   if(Food->CursorLocationV==VertGlobal&&Food->CursorLocationH==HorizontalLocation){
    if(VerticalLocation == Food->arrLocation){
        ByteSnake[VerticalLocation]+=Food->Foods[Food->arrLocation];
        Serial.print(ByteSnake[VerticalLocation]);
      }
      ByteSnake[Food->arrLocation] = Food->RandomPixelLocation; 
    }
  }
