#include "cWorld.h"

cWorld::cWorld(const LiquidCrystal_I2C* L,const cFood* F){
    LCD = L;
    Food = F;
  }
void cWorld::DrawingUnits(bool Horizontal=false, int HorizontalLocation=0, int VertGlobal=0){
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
