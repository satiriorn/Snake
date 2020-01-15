#include "cWorld.h"

cWorld::cWorld(const LiquidCrystal_I2C* L, const cFood* F){
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
void cWorld::CreateWorld(const int &ScaleH, const int &ScaleV){
  int x = ScaleH*ScaleV;
    for(int i = 0; i<=x;i++){
      for(int j = 0; j<8; j++){
        WorldBlocks[i][j] = B00000;
        }
    }
    Create = false;
  }
  
void cWorld::CheckWorld(const int &VertGlobal,const int &HorizontalLocation, byte* ByteSnake, const int &VerticalLocation){
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
  
